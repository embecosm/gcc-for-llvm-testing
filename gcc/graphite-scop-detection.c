/* Detection of Static Control Parts (SCoP) for Graphite.
   Copyright (C) 2009-2015 Free Software Foundation, Inc.
   Contributed by Sebastian Pop <sebastian.pop@amd.com> and
   Tobias Grosser <grosser@fim.uni-passau.de>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"

#ifdef HAVE_isl
/* Workaround for GMP 5.1.3 bug, see PR56019.  */
#include <stddef.h>

#include <isl/constraint.h>
#include <isl/set.h>
#include <isl/map.h>
#include <isl/union_map.h>

#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "cfghooks.h"
#include "params.h"
#include "tree.h"
#include "gimple.h"
#include "ssa.h"
#include "fold-const.h"
#include "gimple-iterator.h"
#include "tree-ssa-loop-manip.h"
#include "tree-ssa-loop-niter.h"
#include "tree-ssa-loop.h"
#include "tree-into-ssa.h"
#include "tree-ssa.h"
#include "cfgloop.h"
#include "tree-data-ref.h"
#include "tree-scalar-evolution.h"
#include "tree-pass.h"
#include "graphite-poly.h"
#include "tree-ssa-propagate.h"
#include "graphite-scop-detection.h"
#include "gimple-pretty-print.h"

/* Lightweight representation of sese for scop detection.
   TODO: Make all this as a constant_edge.  */
struct sese_l
{
  sese_l (edge e, edge x)
  : entry (e), exit (x)
  { }

  /* This is to push objects of sese_l in a vec.  */
  sese_l (int i)
  : entry (NULL), exit (NULL)
  {
    gcc_assert (i == 0);
  }

  operator bool () const
  {
    return entry && exit;
  }

  const sese_l&
  operator= (const sese_l &s)
  {
    entry = s.entry;
    exit = s.exit;
    return *this;
  }

  edge entry;
  edge exit;
};

/* APIs for getting entry/exit of an sese.  */
static basic_block
get_entry_bb (edge e)
{
  return e->dest;
}

static basic_block
get_exit_bb (edge e)
{
  return e->src;
}

class debug_printer
{
private:
  FILE *dump_file;
public:
  void set_dump_file (FILE *f)
  {
    gcc_assert (f);
    dump_file = f;
  }

  friend debug_printer &operator<<(debug_printer &output, int i)
  {
    fprintf (output.dump_file, "%d", i);
    return output;
  }
  friend debug_printer &operator<<(debug_printer &output, const char *s)
  {
    fprintf (output.dump_file, "%s", s);
    return output;
  }
} dp;

#define DEBUG_PRINT(args) do \
    {								\
      if (dump_file && (dump_flags & TDF_DETAILS)) { args; }	\
    } while (0);


/* Return true if BB is empty, contains only DEBUG_INSNs.  */

static bool
trivially_empty_bb_p (basic_block bb)
{
  gimple_stmt_iterator gsi;

  for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
    if (gimple_code (gsi_stmt (gsi)) != GIMPLE_DEBUG)
      return false;

  return true;
}


/* Forward declarations.  */
static void make_close_phi_nodes_unique (basic_block);

/* Something like "n * m" is not allowed.  */

static bool
graphite_can_represent_init (tree e)
{
  switch (TREE_CODE (e))
    {
    case POLYNOMIAL_CHREC:
      return graphite_can_represent_init (CHREC_LEFT (e))
	&& graphite_can_represent_init (CHREC_RIGHT (e));

    case MULT_EXPR:
      if (chrec_contains_symbols (TREE_OPERAND (e, 0)))
	return graphite_can_represent_init (TREE_OPERAND (e, 0))
	  && tree_fits_shwi_p (TREE_OPERAND (e, 1));
      else
	return graphite_can_represent_init (TREE_OPERAND (e, 1))
	  && tree_fits_shwi_p (TREE_OPERAND (e, 0));

    case PLUS_EXPR:
    case POINTER_PLUS_EXPR:
    case MINUS_EXPR:
      return graphite_can_represent_init (TREE_OPERAND (e, 0))
	&& graphite_can_represent_init (TREE_OPERAND (e, 1));

    case NEGATE_EXPR:
    case BIT_NOT_EXPR:
    CASE_CONVERT:
    case NON_LVALUE_EXPR:
      return graphite_can_represent_init (TREE_OPERAND (e, 0));

   default:
     break;
    }

  return true;
}

/* Return true when SCEV can be represented in the polyhedral model.

   An expression can be represented, if it can be expressed as an
   affine expression.  For loops (i, j) and parameters (m, n) all
   affine expressions are of the form:

   x1 * i + x2 * j + x3 * m + x4 * n + x5 * 1 where x1..x5 element of Z

   1 i + 20 j + (-2) m + 25

   Something like "i * n" or "n * m" is not allowed.  */

static bool
graphite_can_represent_scev (tree scev)
{
  if (chrec_contains_undetermined (scev))
    return false;

  /* We disable the handling of pointer types, because it’s currently not
     supported by Graphite with the ISL AST generator. SSA_NAME nodes are
     the only nodes, which are disabled in case they are pointers to object
     types, but this can be changed.  */

  if (POINTER_TYPE_P (TREE_TYPE (scev)) && TREE_CODE (scev) == SSA_NAME)
    return false;

  switch (TREE_CODE (scev))
    {
    case NEGATE_EXPR:
    case BIT_NOT_EXPR:
    CASE_CONVERT:
    case NON_LVALUE_EXPR:
      return graphite_can_represent_scev (TREE_OPERAND (scev, 0));

    case PLUS_EXPR:
    case POINTER_PLUS_EXPR:
    case MINUS_EXPR:
      return graphite_can_represent_scev (TREE_OPERAND (scev, 0))
	&& graphite_can_represent_scev (TREE_OPERAND (scev, 1));

    case MULT_EXPR:
      return !CONVERT_EXPR_CODE_P (TREE_CODE (TREE_OPERAND (scev, 0)))
	&& !CONVERT_EXPR_CODE_P (TREE_CODE (TREE_OPERAND (scev, 1)))
	&& !(chrec_contains_symbols (TREE_OPERAND (scev, 0))
	     && chrec_contains_symbols (TREE_OPERAND (scev, 1)))
	&& graphite_can_represent_init (scev)
	&& graphite_can_represent_scev (TREE_OPERAND (scev, 0))
	&& graphite_can_represent_scev (TREE_OPERAND (scev, 1));

    case POLYNOMIAL_CHREC:
      /* Check for constant strides.  With a non constant stride of
	 'n' we would have a value of 'iv * n'.  Also check that the
	 initial value can represented: for example 'n * m' cannot be
	 represented.  */
      if (!evolution_function_right_is_integer_cst (scev)
	  || !graphite_can_represent_init (scev))
	return false;
      return graphite_can_represent_scev (CHREC_LEFT (scev));

    default:
      break;
    }

  /* Only affine functions can be represented.  */
  if (tree_contains_chrecs (scev, NULL)
      || !scev_is_linear_expression (scev))
    return false;

  return true;
}


/* Return true when EXPR can be represented in the polyhedral model.

   This means an expression can be represented, if it is linear with respect to
   the loops and the strides are non parametric.  LOOP is the place where the
   expr will be evaluated.  SCOP defines the region we analyse.  */

static bool
graphite_can_represent_expr (sese_l scop, loop_p loop, tree expr)
{
  sese region = new_sese (scop.entry, scop.exit);
  tree scev = scalar_evolution_in_region (region, loop, expr);
  free_sese (region);
  return graphite_can_represent_scev (scev);
}

/* Return true if the data references of STMT can be represented by Graphite.
   We try to analyze the data references in a loop contained in the SCOP.  */

static bool
stmt_has_simple_data_refs_p (sese_l scop, gimple *stmt)
{
  sese region = new_sese (scop.entry, scop.exit);
  loop_p nest = outermost_loop_in_sese (region, gimple_bb (stmt));
  loop_p loop = loop_containing_stmt (stmt);
  vec<data_reference_p> drs = vNULL;

  graphite_find_data_references_in_stmt (nest, loop, stmt, &drs);

  int j;
  data_reference_p dr;
  FOR_EACH_VEC_ELT (drs, j, dr)
    {
      int nb_subscripts = DR_NUM_DIMENSIONS (dr);

      if (nb_subscripts < 1)
	{
	  free_data_refs (drs);
	  return false;
	}

      tree ref = DR_REF (dr);

      for (int i = nb_subscripts - 1; i >= 0; i--)
	{
	  if (!graphite_can_represent_scev (DR_ACCESS_FN (dr, i))
	      || (TREE_CODE (ref) != ARRAY_REF
		  && TREE_CODE (ref) != MEM_REF
		  && TREE_CODE (ref) != COMPONENT_REF))
	    {
	      free_data_refs (drs);
	      return false;
	    }

	  ref = TREE_OPERAND (ref, 0);
	}
    }

  free_data_refs (drs);
  return true;
}

/* Return true only when STMT is simple enough for being handled by Graphite.
   This depends on SCOP, as the parameters are initialized relatively to
   this basic block, the linear functions are initialized based on the outermost
   loop containing STMT inside the SCOP.  BB is the place where we try to
   evaluate the STMT.  */

static bool
stmt_simple_for_scop_p (sese_l scop, gimple *stmt, basic_block bb)
{
  loop_p loop = bb->loop_father;

  gcc_assert (scop);

  /* GIMPLE_ASM and GIMPLE_CALL may embed arbitrary side effects.
     Calls have side-effects, except those to const or pure
     functions.  */
  if (gimple_has_volatile_ops (stmt)
      || (gimple_code (stmt) == GIMPLE_CALL
	  && !(gimple_call_flags (stmt) & (ECF_CONST | ECF_PURE)))
      || (gimple_code (stmt) == GIMPLE_ASM))
    {
      DEBUG_PRINT (dp << "[scop-detection-fail] "
		      << "Graphite cannot handle this stmt:\n";
	print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS|TDF_MEMSYMS));
      return false;
    }

  if (is_gimple_debug (stmt))
    return true;

  if (!stmt_has_simple_data_refs_p (scop, stmt))
    {
      DEBUG_PRINT (dp << "[scop-detection-fail] "
		      << "Graphite cannot handle data-refs in stmt:\n";
	print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS|TDF_MEMSYMS););
      return false;
    }

  switch (gimple_code (stmt))
    {
    case GIMPLE_LABEL:
      return true;

    case GIMPLE_COND:
      {
	/* We can handle all binary comparisons.  Inequalities are
	   also supported as they can be represented with union of
	   polyhedra.  */
        enum tree_code code = gimple_cond_code (stmt);
        if (!(code == LT_EXPR
	      || code == GT_EXPR
	      || code == LE_EXPR
	      || code == GE_EXPR
	      || code == EQ_EXPR
	      || code == NE_EXPR))
          {
	    DEBUG_PRINT (dp <<  "[scop-detection-fail] "
			    << "Graphite cannot handle cond stmt:\n";
	      print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS|TDF_MEMSYMS));
	    return false;
	  }

	for (unsigned i = 0; i < 2; ++i)
	  {
	    tree op = gimple_op (stmt, i);
	    if (!graphite_can_represent_expr (scop, loop, op)
		/* We can only constrain on integer type.  */
		|| (TREE_CODE (TREE_TYPE (op)) != INTEGER_TYPE))
	      {
		DEBUG_PRINT (dp <<  "[scop-detection-fail] "
			        << "Graphite cannot represent stmt:\n";
		  print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS|TDF_MEMSYMS));
		return false;
	      }
	  }

	return true;
      }

    case GIMPLE_ASSIGN:
    case GIMPLE_CALL:
      return true;

    default:
      /* These nodes cut a new scope.  */
      DEBUG_PRINT (dp << "[scop-detection-fail] "
		      << "Gimple stmt not handled in Graphite:\n";
	print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS|TDF_MEMSYMS));
      return false;
    }

  return false;
}

/* Return true when BB contains a harmful operation for a scop: that
   can be a function call with side effects, the induction variables
   are not linear with respect to SCOP, etc.  The current open
   scop should end before this statement.  */

static bool
harmful_stmt_in_bb (sese_l scop, basic_block bb)
{
  gimple_stmt_iterator gsi;

  for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
    if (!stmt_simple_for_scop_p (scop, gsi_stmt (gsi), bb))
      return true;

  return false;
}

/* Returns true when P1 and P2 are close phis with the same
   argument.  */

static inline bool
same_close_phi_node (gphi *p1, gphi *p2)
{
  return operand_equal_p (gimple_phi_arg_def (p1, 0),
			  gimple_phi_arg_def (p2, 0), 0);
}

/* Remove the close phi node at GSI and replace its rhs with the rhs
   of PHI.  */

static void
remove_duplicate_close_phi (gphi *phi, gphi_iterator *gsi)
{
  gimple *use_stmt;
  use_operand_p use_p;
  imm_use_iterator imm_iter;
  tree res = gimple_phi_result (phi);
  tree def = gimple_phi_result (gsi->phi ());

  gcc_assert (same_close_phi_node (phi, gsi->phi ()));

  FOR_EACH_IMM_USE_STMT (use_stmt, imm_iter, def)
    {
      FOR_EACH_IMM_USE_ON_STMT (use_p, imm_iter)
	SET_USE (use_p, res);

      update_stmt (use_stmt);
      
      /* It is possible that we just created a duplicate close-phi
	 for an already-processed containing loop.  Check for this
	 case and clean it up.  */
      if (gimple_code (use_stmt) == GIMPLE_PHI
	  && gimple_phi_num_args (use_stmt) == 1)
	make_close_phi_nodes_unique (gimple_bb (use_stmt));
    }

  remove_phi_node (gsi, true);
}

/* Removes all the close phi duplicates from BB.  */

static void
make_close_phi_nodes_unique (basic_block bb)
{
  gphi_iterator psi;

  for (psi = gsi_start_phis (bb); !gsi_end_p (psi); gsi_next (&psi))
    {
      gphi_iterator gsi = psi;
      gphi *phi = psi.phi ();

      /* At this point, PHI should be a close phi in normal form.  */
      gcc_assert (gimple_phi_num_args (phi) == 1);

      /* Iterate over the next phis and remove duplicates.  */
      gsi_next (&gsi);
      while (!gsi_end_p (gsi))
	if (same_close_phi_node (phi, gsi.phi ()))
	  remove_duplicate_close_phi (phi, &gsi);
	else
	  gsi_next (&gsi);
    }
}

/* Transforms LOOP to the canonical loop closed SSA form.  */

static void
canonicalize_loop_closed_ssa (loop_p loop)
{
  edge e = single_exit (loop);
  basic_block bb;

  if (!e || e->flags & EDGE_ABNORMAL)
    return;

  bb = e->dest;

  if (single_pred_p (bb))
    {
      e = split_block_after_labels (bb);
      DEBUG_PRINT (dp << "\nSplitting bb_" << bb->index);
      make_close_phi_nodes_unique (e->src);
    }
  else
    {
      gphi_iterator psi;
      basic_block close = split_edge (e);

      e = single_succ_edge (close);
      DEBUG_PRINT (dp << "\nSplitting edge ("
		      << e->src->index << "," << e->dest->index
		      << ")\n");

      for (psi = gsi_start_phis (bb); !gsi_end_p (psi); gsi_next (&psi))
	{
	  gphi *phi = psi.phi ();
	  unsigned i;

	  for (i = 0; i < gimple_phi_num_args (phi); i++)
	    if (gimple_phi_arg_edge (phi, i) == e)
	      {
		tree res, arg = gimple_phi_arg_def (phi, i);
		use_operand_p use_p;
		gphi *close_phi;

		if (TREE_CODE (arg) != SSA_NAME)
		  continue;

		close_phi = create_phi_node (NULL_TREE, close);
		res = create_new_def_for (arg, close_phi,
					  gimple_phi_result_ptr (close_phi));
		add_phi_arg (close_phi, arg,
			     gimple_phi_arg_edge (close_phi, 0),
			     UNKNOWN_LOCATION);
		use_p = gimple_phi_arg_imm_use_ptr (phi, i);
		replace_exp (use_p, res);
		update_stmt (phi);
	      }
	}

      make_close_phi_nodes_unique (close);
    }

  /* The code above does not properly handle changes in the post dominance
     information (yet).  */
  recompute_all_dominators ();
}

/* Converts the current loop closed SSA form to a canonical form
   expected by the Graphite code generation.

   The loop closed SSA form has the following invariant: a variable
   defined in a loop that is used outside the loop appears only in the
   phi nodes in the destination of the loop exit.  These phi nodes are
   called close phi nodes.

   The canonical loop closed SSA form contains the extra invariants:

   - when the loop contains only one exit, the close phi nodes contain
   only one argument.  That implies that the basic block that contains
   the close phi nodes has only one predecessor, that is a basic block
   in the loop.

   - the basic block containing the close phi nodes does not contain
   other statements.

   - there exist only one phi node per definition in the loop.
*/

static void
canonicalize_loop_closed_ssa_form (void)
{
  loop_p loop;

#ifdef ENABLE_CHECKING
  verify_loop_closed_ssa (true);
#endif

  FOR_EACH_LOOP (loop, 0)
    canonicalize_loop_closed_ssa (loop);

  rewrite_into_loop_closed_ssa (NULL, TODO_update_ssa);
  update_ssa (TODO_update_ssa);

#ifdef ENABLE_CHECKING
  verify_loop_closed_ssa (true);
#endif
}

/* Pretty print to FILE all the SCoPs in DOT format and mark them with
   different colors.  If there are not enough colors, paint the
   remaining SCoPs in gray.

   Special nodes:
   - "*" after the node number denotes the entry of a SCoP,
   - "#" after the node number denotes the exit of a SCoP,
   - "()" around the node number denotes the entry or the
     exit nodes of the SCOP.  These are not part of SCoP.  */

static void
dot_all_scops_1 (FILE *file, vec<scop_p> scops)
{
  basic_block bb;
  edge e;
  edge_iterator ei;
  scop_p scop;
  const char* color;
  int i;

  /* Disable debugging while printing graph.  */
  int tmp_dump_flags = dump_flags;
  dump_flags = 0;

  fprintf (file, "digraph all {\n");

  FOR_ALL_BB_FN (bb, cfun)
    {
      int part_of_scop = false;

      /* Use HTML for every bb label.  So we are able to print bbs
         which are part of two different SCoPs, with two different
         background colors.  */
      fprintf (file, "%d [label=<\n  <TABLE BORDER=\"0\" CELLBORDER=\"1\" ",
                     bb->index);
      fprintf (file, "CELLSPACING=\"0\">\n");

      /* Select color for SCoP.  */
      FOR_EACH_VEC_ELT (scops, i, scop)
	{
	  sese region = SCOP_REGION (scop);
	  if (bb_in_sese_p (bb, region)
	      || (SESE_EXIT_BB (region) == bb)
	      || (SESE_ENTRY_BB (region) == bb))
	    {
	      switch (i % 17)
		{
		case 0: /* red */
		  color = "#e41a1c";
		  break;
		case 1: /* blue */
		  color = "#377eb8";
		  break;
		case 2: /* green */
		  color = "#4daf4a";
		  break;
		case 3: /* purple */
		  color = "#984ea3";
		  break;
		case 4: /* orange */
		  color = "#ff7f00";
		  break;
		case 5: /* yellow */
		  color = "#ffff33";
		  break;
		case 6: /* brown */
		  color = "#a65628";
		  break;
		case 7: /* rose */
		  color = "#f781bf";
		  break;
		case 8:
		  color = "#8dd3c7";
		  break;
		case 9:
		  color = "#ffffb3";
		  break;
		case 10:
		  color = "#bebada";
		  break;
		case 11:
		  color = "#fb8072";
		  break;
		case 12:
		  color = "#80b1d3";
		  break;
		case 13:
		  color = "#fdb462";
		  break;
		case 14:
		  color = "#b3de69";
		  break;
		case 15:
		  color = "#fccde5";
		  break;
		case 16:
		  color = "#bc80bd";
		  break;
		default: /* gray */
		  color = "#999999";
		}

	      fprintf (file, "    <TR><TD WIDTH=\"50\" BGCOLOR=\"%s\">", color);

	      if (!bb_in_sese_p (bb, region))
		fprintf (file, " (");

	      if (bb == SESE_ENTRY_BB (region)
		  && bb == SESE_EXIT_BB (region))
		fprintf (file, " %d*# ", bb->index);
	      else if (bb == SESE_ENTRY_BB (region))
		fprintf (file, " %d* ", bb->index);
	      else if (bb == SESE_EXIT_BB (region))
		fprintf (file, " %d# ", bb->index);
	      else
		fprintf (file, " %d ", bb->index);

	      fprintf (file, "{lp_%d}", bb->loop_father->num);

	      if (!bb_in_sese_p (bb,region))
		fprintf (file, ")");

	      fprintf (file, "</TD></TR>\n");
	      part_of_scop  = true;
	    }
	}

      if (!part_of_scop)
	{
	  fprintf (file, "    <TR><TD WIDTH=\"50\" BGCOLOR=\"#ffffff\">");
	  fprintf (file, " %d {lp_%d} </TD></TR>\n",
		   bb->index, bb->loop_father->num);
	}
      fprintf (file, "  </TABLE>>, shape=box, style=\"setlinewidth(0)\"]\n");
    }

  FOR_ALL_BB_FN (bb, cfun)
    {
      FOR_EACH_EDGE (e, ei, bb->succs)
	      fprintf (file, "%d -> %d;\n", bb->index, e->dest->index);
    }

  fputs ("}\n\n", file);

  /* Enable debugging again.  */
  dump_flags = tmp_dump_flags;
}

/* Display all SCoPs using dotty.  */

DEBUG_FUNCTION void
dot_all_scops (vec<scop_p> scops)
{
  /* When debugging, enable the following code.  This cannot be used
     in production compilers because it calls "system".  */
#if 0
  int x;
  FILE *stream = fopen ("/tmp/allscops.dot", "w");
  gcc_assert (stream);

  dot_all_scops_1 (stream, scops);
  fclose (stream);

  x = system ("dotty /tmp/allscops.dot &");
#else
  dot_all_scops_1 (stderr, scops);
#endif
}

/* Display all SCoPs using dotty.  */

DEBUG_FUNCTION void
dot_scop (scop_p scop)
{
  auto_vec<scop_p, 1> scops;

  if (scop)
    scops.safe_push (scop);

  /* When debugging, enable the following code.  This cannot be used
     in production compilers because it calls "system".  */
#if 0
  {
    int x;
    FILE *stream = fopen ("/tmp/allscops.dot", "w");
    gcc_assert (stream);

    dot_all_scops_1 (stream, scops);
    fclose (stream);
    x = system ("dotty /tmp/allscops.dot &");
  }
#else
  dot_all_scops_1 (stderr, scops);
#endif
}

/* Return true when the body of LOOP has statements that can be represented as a
   valid scop.  */

static bool
loop_body_is_valid_scop (loop_p loop, sese_l scop)
{
  if (!loop_nest_has_data_refs (loop))
    {
      DEBUG_PRINT (dp << "[scop-detection-fail] loop_"
		      << loop->num << "does not have any data reference.\n");
      return false;
    }

  basic_block *bbs = get_loop_body (loop);
  for (unsigned i = 0; i < loop->num_nodes; i++)
    {
      basic_block bb = bbs[i];

      if (harmful_stmt_in_bb (scop, bb))
	return false;
    }
  free (bbs);

  if (loop->inner)
    {
      loop = loop->inner;
      while (loop)
	{
	  if (!loop_body_is_valid_scop (loop, scop))
	    return false;
	  loop = loop->next;
	}
    }

  return true;
}

/* Build the maximal scop containing LOOP(s) and add it to SCOPS.  */

class scop_builder
{
 public:
  scop_builder ()
    : scops (vNULL)
  { }

  static sese_l invalid_sese;

  vec<sese_l>
    get_scops ()
  {
    return scops;
  }

  sese_l
    get_sese (loop_p loop)
  {
    if (!loop)
      return invalid_sese;

    if (!loops_state_satisfies_p (LOOPS_HAVE_PREHEADERS))
      return invalid_sese;
    edge scop_end = single_exit (loop);
    if (!scop_end)
      return invalid_sese;
    edge scop_begin = loop_preheader_edge (loop);
    sese_l s (scop_begin, scop_end);
    return s;
  }

  static edge
    get_nearest_dom_with_single_entry (basic_block dom)
  {
    if (!dom->preds)
      return NULL;
    /* If e1->src dominates e2->src then e1->src will also dominate dom.  */
    if (dom->preds->length () == 2)
      {
	edge e1 = (*dom->preds)[0];
	edge e2 = (*dom->preds)[1];
	if (dominated_by_p (CDI_DOMINATORS, e2->src, e1->src))
	  return e1;
	if (dominated_by_p (CDI_DOMINATORS, e1->src, e2->src))
	  return e2;
      }

    while (dom->preds->length () != 1)
      {
	if (dom->preds->length () < 1)
	  return NULL;
	dom = get_immediate_dominator (CDI_DOMINATORS, dom);
	if (!dom->preds)
	  return NULL;
      }
    return (*dom->preds)[0];
  }

  static edge
    get_nearest_pdom_with_single_exit (basic_block dom)
  {
    if (!dom->succs)
      return NULL;
    if (dom->succs->length () == 2)
      {
	edge e1 = (*dom->succs)[0];
	edge e2 = (*dom->succs)[1];
	if (dominated_by_p (CDI_POST_DOMINATORS, e2->dest, e1->dest))
	  return e1;
	if (dominated_by_p (CDI_POST_DOMINATORS, e1->dest, e2->dest))
	  return e2;
      }

    while (dom->succs->length () != 1)
      {
	if (dom->succs->length () < 1)
	  return NULL;
	dom = get_immediate_dominator (CDI_POST_DOMINATORS, dom);
	if (!dom->succs)
	  return NULL;
      }
    return (*dom->succs)[0];
  }

  /* Print S to FILE.  */

  static void
    print_sese (FILE *file, sese_l s)
  {
    fprintf (file, "(entry_edge (bb_%d, bb_%d), exit_edge (bb_%d, bb_%d))\n",
	     s.entry->src->index, s.entry->dest->index,
	     s.exit->src->index, s.exit->dest->index);
  }

  /* Merge scops at same loop depth and returns the new sese.
     Returns a new SESE when merge was successful, INVALID_SESE otherwise.  */

  static sese_l
    merge_sese (sese_l first, sese_l second)
  {
    /* In the trivial case first/second may be NULL.  */
    if (!first)
      return second;
    if (!second)
      return first;

    DEBUG_PRINT (dp << "[try-merging-sese] s1: ";
		 print_sese (dump_file, first);
		 dp << "[try-merging-sese] s2: ";
		 print_sese (dump_file, second));

    /* Assumption: Both the sese's should be at the same loop depth or one scop
       should subsume the other like in case of nested loops.  */

    /* Find the common dominators for entry,
       and common post-dominators for the exit.  */
    basic_block dom = nearest_common_dominator (CDI_DOMINATORS,
						get_entry_bb (first.entry),
						get_entry_bb (second.entry));


    edge entry = get_nearest_dom_with_single_entry (dom);
    if (!entry)
      return invalid_sese;

    basic_block pdom = nearest_common_dominator (CDI_POST_DOMINATORS,
						 get_exit_bb (first.exit),
						 get_exit_bb (second.exit));
    pdom = nearest_common_dominator (CDI_POST_DOMINATORS, dom, pdom);

    edge exit = get_nearest_pdom_with_single_exit (pdom);
    if (!exit)
      return invalid_sese;

    sese_l combined (entry, exit);

    /* FIXME: We could iterate to find the dom which dominates pdom, and pdom
       which post-dominates dom, until it stabilizes.  Also, ENTRY->SRC and
       EXIT->DEST should be in the same loop nest.  */
    if (!dominated_by_p (CDI_DOMINATORS, pdom, dom)
	|| loop_depth (entry->src->loop_father)
	   != loop_depth (exit->dest->loop_father))
      return invalid_sese;

    /* For now we just want to bail out when exit does not post-dominate entry.
       TODO: We might just add a basic_block at the exit to make exit
       post-dominate entry (the entire region).  */
    if (!dominated_by_p (CDI_POST_DOMINATORS, get_entry_bb (entry),
                         get_exit_bb (exit))
	|| !dominated_by_p (CDI_DOMINATORS, get_exit_bb (exit),
			    get_entry_bb (entry)))
      {
	DEBUG_PRINT (dp <<  "[scop-detection-fail] cannot merge seses.\n");
	return invalid_sese;
      }

    /* FIXME: We should remove this piece of code once
       canonicalize_loop_closed_ssa has been removed, because that function
       adds a BB with single exit.  */
    if (!trivially_empty_bb_p (get_exit_bb (combined.exit)))
      {
	/* Find the first empty succ (with single exit) of combined.exit.  */
	basic_block imm_succ = combined.exit->dest;
	if (single_succ_p (imm_succ) && trivially_empty_bb_p (imm_succ))
	  combined.exit = single_succ_edge (imm_succ);
	else
	  {
	    DEBUG_PRINT (dp << "\n[scop-detection-fail] Discarding SCoP because "
			    << "no single exit (empty succ) for sese exit";
			 print_sese (dump_file, combined));
	    return invalid_sese;
	  }
      }

    /* Analyze all the BBs in new sese.  */
    if (harmful_stmt_in_region (combined))
      return invalid_sese;

    DEBUG_PRINT (dp <<  "[merged-sese] s1: ";
		 print_sese (dump_file, combined));

    return combined;
  }

  /* Build scop outer->inner if possible.  */
  sese_l
    build_scop_depth (sese_l s, loop_p loop)
  {
    if (!loop)
      return s;

    DEBUG_PRINT (dp << "\n[Depth loop_" << loop->num << "]");
    s = build_scop_depth (s, loop->inner);

    sese_l s2 = merge_sese (s, get_sese (loop));
    if (!s2)
      {
	/* s might be a valid scop, so return it and start analyzing from the
	   adjacent loop.  */
	build_scop_depth (invalid_sese, loop->next);
	return s;
      }

    if (!loop_is_valid_scop (loop, s2))
      return build_scop_depth (invalid_sese, loop->next);

    return build_scop_breadth (s2, loop);
  }

  /* If loop and loop->next are valid scops, try to merge them.  */

  sese_l
    build_scop_breadth (sese_l s1, loop_p loop)
  {
    if (!loop)
      return s1;
    DEBUG_PRINT (dp << "\n[Breadth loop_" << loop->num << "]");
    gcc_assert (s1);

    loop_p l = loop;
    sese_l s2 = build_scop_depth (invalid_sese, l->next);
    if (!s2)
      {
	if (s1)
	  add_scop (s1);
	return s1;
      }

    sese_l combined = merge_sese (s1, s2);

    if (combined)
      s1 = combined;
    else
      add_scop (s2);

    if (s1)
      add_scop (s1);
    return s1;
  }

  /* Returns true when Graphite can represent LOOP in SCOP.
     FIXME: For the moment, graphite cannot be used on loops that iterate using
     induction variables that wrap.  */
  static bool
    can_represent_loop_1 (loop_p loop, sese_l scop)
  {
    tree niter;
    struct tree_niter_desc niter_desc;

    return single_exit (loop)
      && number_of_iterations_exit (loop, single_exit (loop), &niter_desc, false)
      && niter_desc.control.no_overflow
      && (niter = number_of_latch_executions (loop))
      && !chrec_contains_undetermined (niter)
      && graphite_can_represent_expr (scop, loop, niter);
  }

  /* Return true when all the loops within LOOP can be represented by
     Graphite.  */

  static bool
    can_represent_loop (loop_p loop, sese_l scop)
  {
    if (!can_represent_loop_1 (loop, scop))
      return false;
    if (loop->inner && !can_represent_loop (loop->inner, scop))
      return false;
    if (loop->next && !can_represent_loop (loop->next, scop))
      return false;

    return true;
  }

  /* Return true when LOOP is a valid scop, that is a Static Control Part, a
     region of code that can be represented in the polyhedral model.  SCOP
     defines the region we analyse.  */

  static bool
    loop_is_valid_scop (loop_p loop, sese_l scop)
  {
    if (!scop)
      return false;

    if (!can_represent_loop (loop, scop))
      {
	DEBUG_PRINT (dp << "[scop-detection-fail] cannot represent loop_"
		        << loop->num << "\n");
	return false;
      }

    if (loop_body_is_valid_scop (loop, scop))
      {
	DEBUG_PRINT (dp << "[valid-scop] loop_"
		        << loop->num << "is a valid scop.\n");
	return true;
      }
    return false;
  }

  /* Return true when BEGIN is the preheader edge of a loop with a single exit
     END.  */

  static bool
    region_has_one_loop (sese_l s)
  {
    edge begin = s.entry;
    edge end = s.exit;
    /* Check for a single perfectly nested loop.  */
    if (begin->dest->loop_father->inner)
      return false;

    /* Otherwise, check whether we have adjacent loops.  */
    return begin->dest->loop_father == end->src->loop_father;
  }

  /* Add to SCOPS a scop starting at SCOP_BEGIN and ending at SCOP_END.  */

  void
    add_scop (sese_l s)
  {
    gcc_assert (s);

    /* Do not add scops with only one loop.  */
    if (region_has_one_loop (s))
      {
	DEBUG_PRINT (dp << "\n[scop-detection-fail] Discarding one loop SCoP";
		     print_sese (dump_file, s));
	return;
      }

    if (get_exit_bb (s.exit) == EXIT_BLOCK_PTR_FOR_FN (cfun))
      {
	DEBUG_PRINT (dp << "\n[scop-detection-fail] "
		        << "Discarding SCoP exiting to return";
		     print_sese (dump_file, s));
	return;
      }

    /* Remove all the scops which are subsumed by s.  */
    remove_subscops (s);

    /* Replace this with split-intersecting scops.  */
    remove_intersecting_scops (s);

    scops.safe_push (s);
    DEBUG_PRINT (dp << "\nAdding SCoP "; print_sese (dump_file, s));
  }

  /* Return true when a statement in SCOP cannot be represented by Graphite.
     The assumptions are that L1 dominates L2, and SCOP->entry dominates L1.
     Limit the number of bbs between adjacent loops to
     PARAM_SCOP_MAX_NUM_BBS_BETWEEN_LOOPS.  */

  static bool
    harmful_stmt_in_region (sese_l scop)
  {
    basic_block exit_bb = get_exit_bb (scop.exit);
    basic_block entry_bb = get_entry_bb (scop.entry);

    DEBUG_PRINT (dp << "\n[checking-harmful-bbs] ";
		 print_sese (dump_file, scop));
    gcc_assert (dominated_by_p (CDI_DOMINATORS, exit_bb, entry_bb));

    int depth = bb_dom_dfs_in (CDI_DOMINATORS, exit_bb)
      - bb_dom_dfs_in (CDI_DOMINATORS, entry_bb);

    gcc_assert (depth >0);

    vec<basic_block> dom = get_dominated_to_depth (CDI_DOMINATORS,
						   entry_bb, depth);
    int i;
    basic_block bb;
    FOR_EACH_VEC_ELT (dom, i, bb)
      {
	DEBUG_PRINT (dp << "\nVisiting bb_" << bb->index);

	/* We don't want to analyze any bb outside sese.  */
	if (!dominated_by_p (CDI_POST_DOMINATORS, bb, exit_bb))
	  continue;

	if (harmful_stmt_in_bb (scop, bb))
	  return true;
      }

    return false;
  }

  /* Returns true if S1 subsumes/surrounds S2.  */
  static bool
    subsumes (sese_l s1, sese_l s2)
  {
    if (dominated_by_p (CDI_DOMINATORS, get_entry_bb (s2.entry),
			get_entry_bb (s1.entry))
	&& dominated_by_p (CDI_POST_DOMINATORS, get_entry_bb (s2.exit),
			   get_entry_bb (s1.exit)))
      return true;
    return false;
  }

  /* Remove a SCoP which is subsumed by S1.  */
  void
    remove_subscops (sese_l s1)
  {
    int j;
    sese_l s2 (0);
    FOR_EACH_VEC_ELT_REVERSE (scops, j, s2)
      {
	if (subsumes (s1, s2))
	  {
	    DEBUG_PRINT (dp << "\nRemoving sub-SCoP";
		 print_sese (dump_file, s2));
	    scops.unordered_remove (j);
	  }
      }
  }

  /* Returns true if S1 intersects with S2.  Since we already know that S1 does
     not subsume S2 or vice-versa, we only check for entry bbs.  */

  static bool
    intersects (sese_l s1, sese_l s2)
  {
    if (dominated_by_p (CDI_DOMINATORS, get_entry_bb (s2.entry),
			get_entry_bb (s1.entry))
	&& !dominated_by_p (CDI_DOMINATORS, get_entry_bb (s2.entry),
			    get_exit_bb (s1.exit)))
      return true;
    if ((s1.exit == s2.entry)
	|| (s2.exit == s1.entry))
      return true;

    return false;
  }

  /* Remove one of the scops when it intersects with any other.  */

  void
    remove_intersecting_scops (sese_l s1)
  {
    int j;
    sese_l s2 (0);
    FOR_EACH_VEC_ELT_REVERSE (scops, j, s2)
      {
	if (intersects (s1, s2))
	  {
	    DEBUG_PRINT (dp << "\nRemoving intersecting SCoP";
		print_sese (dump_file, s2);
		dp << "Intersects with:";
		print_sese (dump_file, s1));
	    scops.unordered_remove (j);
	  }
      }
  }

 private:
  vec<sese_l> scops;
};

sese_l scop_builder::invalid_sese (0);

/* Find Static Control Parts (SCoP) in the current function and pushes
   them to SCOPS.  */

void
build_scops (vec<scop_p> *scops)
{
  if (dump_file)
    dp.set_dump_file (dump_file);

  canonicalize_loop_closed_ssa_form ();

  scop_builder sb;
  sb.build_scop_depth (scop_builder::invalid_sese, current_loops->tree_root);

  /* Now create scops from the lightweight SESEs.  */
  vec<sese_l> scops_l = sb.get_scops ();
  int i;
  sese_l s (0);
  FOR_EACH_VEC_ELT (scops_l, i, s)
  {
    sese sese_reg = new_sese (s.entry, s.exit);
    scops->safe_push (new_scop (sese_reg));
  }

  DEBUG_PRINT (dp << "number of SCoPs: " << (scops ? scops->length () : 0););
}

#endif  /* HAVE_isl */
