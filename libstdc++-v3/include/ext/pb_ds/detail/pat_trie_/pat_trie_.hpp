// -*- C++ -*-

// Copyright (C) 2005, 2006 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice
// and this permission notice appear in supporting documentation. None
// of the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.

/**
 * @file pat_trie_.hpp
 * Contains an implementation class for a patricia tree.
 */

/**
 * This implementation loosely borrows ideas from:
 * 1) "Fast Mergeable Integer Maps", Okasaki, Gill 1998
 * 2) "Ptset: Sets of integers implemented as Patricia trees",
 *    Jean-Christophe Filliatr, 2000
 **/

#include <ext/pb_ds/detail/pat_trie_/synth_e_access_traits.hpp>
#include <ext/pb_ds/detail/pat_trie_/node_base.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/detail/eq_fn/eq_by_less.hpp>
#include <ext/pb_ds/detail/types_traits.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/cond_dealtor.hpp>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <iterator>
#include <utility>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <list>
#ifdef PB_DS_USE_MAP_DEBUG_BASE
#include <ext/pb_ds/detail/map_debug_base.hpp>
#endif // #ifdef PB_DS_USE_MAP_DEBUG_BASE

namespace pb_ds
{
  namespace detail
  {

#ifdef PB_DS_PAT_TRIE_DEBUG_
#define PB_DS_DBG_ASSERT(X) assert(X)
#define PB_DS_DBG_VERIFY(X) assert(X)
#define PB_DS_DBG_ONLY(X) X
#else // #ifdef PB_DS_PAT_TRIE_DEBUG_
#define PB_DS_DBG_ASSERT(X)
#define PB_DS_DBG_VERIFY(X) {if((X)==0);}
#define PB_DS_DBG_ONLY(X) ;
#endif // #ifdef PB_DS_PAT_TRIE_DEBUG_

#define PB_DS_CLASS_T_DEC						\
    template<								\
						typename Key,		\
						typename Mapped,	\
						class Node_And_It_Traits, \
						class Allocator>

#ifdef PB_DS_DATA_TRUE_INDICATOR
#define PB_DS_CLASS_NAME			\
    pat_trie_data_
#endif // #ifdef PB_DS_DATA_TRUE_INDICATOR

#ifdef PB_DS_DATA_FALSE_INDICATOR
#define PB_DS_CLASS_NAME			\
    pat_trie_no_data_
#endif // #ifdef PB_DS_DATA_FALSE_INDICATOR

#define PB_DS_CLASS_C_DEC						\
    PB_DS_CLASS_NAME<							\
						Key,			\
						Mapped,			\
						Node_And_It_Traits,	\
						Allocator>

#define PB_DS_TYPES_TRAITS_C_DEC				\
    types_traits<				\
						Key,		\
						Mapped,		\
						Allocator,	\
						false>

#ifdef PB_DS_USE_MAP_DEBUG_BASE
#define PB_DS_MAP_DEBUG_BASE_C_DEC					\
    map_debug_base<					\
								Key,	\
								eq_by_less< \
												Key, \
												std::less< \
														Key> >, \
								typename Allocator::template rebind< \
												     Key>::other::const_reference>
#endif // #ifdef PB_DS_USE_MAP_DEBUG_BASE

#ifdef PB_DS_DATA_TRUE_INDICATOR
#define PB_DS_V2F(X) (X).first
#define PB_DS_V2S(X) (X).second
#define PB_DS_EP2VP(X)& ((X)->m_value)
#endif // #ifdef PB_DS_DATA_TRUE_INDICATOR

#ifdef PB_DS_DATA_FALSE_INDICATOR
#define PB_DS_V2F(X) (X)
#define PB_DS_V2S(X) Mapped_Data()
#define PB_DS_EP2VP(X)& ((X)->m_value.first)
#endif // #ifdef PB_DS_DATA_FALSE_INDICATOR

#define PB_DS_STATIC_ASSERT(UNIQUE, E)					\
    typedef								\
    static_assert_dumclass<				\
									sizeof(static_assert<(bool)(E)>)> \
    UNIQUE##static_assert_type

    /**
     * class description = PATRICIA trie implementation.">
     **/
    template<typename Key,
	     typename Mapped,
	     class Node_And_It_Traits,
	     class Allocator>
    class PB_DS_CLASS_NAME :
#ifdef PB_DS_PAT_TRIE_DEBUG_
      public PB_DS_MAP_DEBUG_BASE_C_DEC,
#endif // #ifdef PB_DS_PAT_TRIE_DEBUG_
      public Node_And_It_Traits::synth_e_access_traits,
      public Node_And_It_Traits::node_update,
      public PB_DS_TYPES_TRAITS_C_DEC
    {

    private:

      typedef
      typename Node_And_It_Traits::synth_e_access_traits
      synth_e_access_traits;

      typedef
      typename Allocator::template rebind<
	synth_e_access_traits>::other::const_pointer
      const_e_access_traits_pointer;

      typedef
      typename synth_e_access_traits::const_iterator
      const_e_iterator;

      typedef typename Node_And_It_Traits::node node;

      typedef
      typename Allocator::template rebind<
	node>::other::const_pointer
      const_node_pointer;

      typedef
      typename Allocator::template rebind<
	node>::other::pointer
      node_pointer;

      typedef typename Node_And_It_Traits::head head;

      typedef
      typename Allocator::template rebind<
	head>::other
      head_allocator;

      typedef typename head_allocator::pointer head_pointer;

      typedef typename Node_And_It_Traits::leaf leaf;

      typedef
      typename Allocator::template rebind<
	leaf>::other
      leaf_allocator;

      typedef typename leaf_allocator::const_pointer const_leaf_pointer;

      typedef typename leaf_allocator::pointer leaf_pointer;

      typedef typename Node_And_It_Traits::internal_node internal_node;

      typedef
      typename Allocator::template rebind<
	internal_node>::other
      internal_node_allocator;

      typedef
      typename internal_node_allocator::const_pointer
      const_internal_node_pointer;

      typedef
      typename internal_node_allocator::pointer
      internal_node_pointer;

      typedef PB_DS_TYPES_TRAITS_C_DEC traits_base;

#include <ext/pb_ds/detail/pat_trie_/cond_dtor_entry_dealtor.hpp>

#ifdef PB_DS_PAT_TRIE_DEBUG_
      typedef PB_DS_MAP_DEBUG_BASE_C_DEC map_debug_base;
#endif // #ifdef PB_DS_PAT_TRIE_DEBUG_

#include <ext/pb_ds/detail/pat_trie_/split_join_branch_bag.hpp>

      typedef
      typename Node_And_It_Traits::null_node_update_pointer
      null_node_update_pointer;

    public:
      typedef pat_trie_tag container_category;

      typedef typename Allocator::size_type size_type;

      typedef typename Allocator::difference_type difference_type;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::key_type key_type;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::key_pointer key_pointer;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::const_key_pointer
      const_key_pointer;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::key_reference key_reference;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::const_key_reference
      const_key_reference;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::mapped_type mapped_type;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::mapped_pointer
      mapped_pointer;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::const_mapped_pointer
      const_mapped_pointer;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::mapped_reference
      mapped_reference;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::const_mapped_reference
      const_mapped_reference;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::value_type value_type;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::pointer pointer;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::const_pointer const_pointer;

      typedef typename PB_DS_TYPES_TRAITS_C_DEC::reference reference;

      typedef
      typename PB_DS_TYPES_TRAITS_C_DEC::const_reference
      const_reference;

      typedef
      typename Node_And_It_Traits::const_iterator
      const_point_iterator;

      typedef typename Node_And_It_Traits::iterator point_iterator;

      typedef const_point_iterator const_iterator;

      typedef point_iterator iterator;

      typedef
      typename Node_And_It_Traits::const_reverse_iterator
      const_reverse_iterator;

      typedef typename Node_And_It_Traits::reverse_iterator reverse_iterator;

      typedef
      typename Node_And_It_Traits::const_node_iterator
      const_node_iterator;

      typedef typename Node_And_It_Traits::node_iterator node_iterator;

      typedef typename Node_And_It_Traits::e_access_traits e_access_traits;

      typedef typename Node_And_It_Traits::node_update node_update;

      typedef Allocator allocator;

    public:

      PB_DS_CLASS_NAME();

      PB_DS_CLASS_NAME(const e_access_traits& r_e_access_traits);

      PB_DS_CLASS_NAME(const PB_DS_CLASS_C_DEC& other);

      void
      swap(PB_DS_CLASS_C_DEC& other);

      ~PB_DS_CLASS_NAME();

      inline bool
      empty() const;

      inline size_type
      size() const;

      inline size_type
      max_size() const;

      e_access_traits& 
      get_e_access_traits();

      const e_access_traits& 
      get_e_access_traits() const;

      node_update& 
      get_node_update();

      const node_update& 
      get_node_update() const;

      inline std::pair<
	point_iterator,
	bool>
      insert(const_reference r_val);

      inline mapped_reference
      operator[](const_key_reference r_key)
      {
#ifdef PB_DS_DATA_TRUE_INDICATOR
	return (insert(std::make_pair(
				      r_key,
				      mapped_type())).first->second);
#else // #ifdef PB_DS_DATA_TRUE_INDICATOR
	insert(r_key);

	return (traits_base::s_null_mapped);
#endif // #ifdef PB_DS_DATA_TRUE
      }

      inline point_iterator
      find(const_key_reference r_key);

      inline const_point_iterator
      find(const_key_reference r_key) const;

      inline point_iterator
      lower_bound(const_key_reference r_key);

      inline const_point_iterator
      lower_bound(const_key_reference r_key) const;

      inline point_iterator
      upper_bound(const_key_reference r_key);

      inline const_point_iterator
      upper_bound(const_key_reference r_key) const;

      void
      clear();

      inline bool
      erase(const_key_reference r_key);

      inline const_iterator
      erase(const_iterator it);

#ifdef PB_DS_DATA_TRUE_INDICATOR
      inline iterator
      erase(iterator it);
#endif // #ifdef PB_DS_DATA_TRUE_INDICATOR

      inline const_reverse_iterator
      erase(const_reverse_iterator it);

#ifdef PB_DS_DATA_TRUE_INDICATOR
      inline reverse_iterator
      erase(reverse_iterator it);
#endif // #ifdef PB_DS_DATA_TRUE_INDICATOR

      template<typename Pred>
      inline size_type
      erase_if(Pred pred);

      void
      join(PB_DS_CLASS_C_DEC& other);

      void
      split(const_key_reference r_key, PB_DS_CLASS_C_DEC& other);

      inline iterator
      begin();

      inline const_iterator
      begin() const;

      inline iterator
      end();

      inline const_iterator
      end() const;

      inline reverse_iterator
      rbegin();

      inline const_reverse_iterator
      rbegin() const;

      inline reverse_iterator
      rend();

      inline const_reverse_iterator
      rend() const;

      inline const_node_iterator
      node_begin() const;

      inline node_iterator
      node_begin();

      inline const_node_iterator
      node_end() const;

      inline node_iterator
      node_end();

#ifdef PB_DS_PAT_TRIE_TRACE_

      void
      trace() const;

#endif // #ifdef PB_DS_PAT_TRIE_TRACE_

    protected:

      template<typename It>
      void
      copy_from_range(It first_it, It last_it);

      void
      value_swap(PB_DS_CLASS_C_DEC& other);

      node_pointer
      recursive_copy_node(const_node_pointer p_other_nd);

    private:

      void
      initialize();

      inline void
      apply_update(node_pointer p_nd, null_node_update_pointer);

      template<typename Node_Update_>
      inline void
      apply_update(node_pointer p_nd, Node_Update_* p_update);

      bool
      join_prep(PB_DS_CLASS_C_DEC& other, split_join_branch_bag& r_bag);

      void
      rec_join_prep(const_node_pointer p_l, const_node_pointer p_r, split_join_branch_bag& r_bag);

      void
      rec_join_prep(const_leaf_pointer p_l, const_leaf_pointer p_r, split_join_branch_bag& r_bag);

      void
      rec_join_prep(const_leaf_pointer p_l, const_internal_node_pointer p_r, split_join_branch_bag& r_bag);

      void
      rec_join_prep(const_internal_node_pointer p_l, const_leaf_pointer p_r, split_join_branch_bag& r_bag);

      void
      rec_join_prep(const_internal_node_pointer p_l, const_internal_node_pointer p_r, split_join_branch_bag& r_bag);

      node_pointer
      rec_join(node_pointer p_l, node_pointer p_r, size_type checked_ind, split_join_branch_bag& r_bag);

      node_pointer
      rec_join(leaf_pointer p_l, leaf_pointer p_r, split_join_branch_bag& r_bag);

      node_pointer
      rec_join(leaf_pointer p_l, internal_node_pointer p_r, size_type checked_ind, split_join_branch_bag& r_bag);

      node_pointer
      rec_join(internal_node_pointer p_l, leaf_pointer p_r, size_type checked_ind, split_join_branch_bag& r_bag);

      node_pointer
      rec_join(internal_node_pointer p_l, internal_node_pointer p_r, split_join_branch_bag& r_bag);

      size_type
      keys_diff_ind(typename e_access_traits::const_iterator b_l, typename e_access_traits::const_iterator e_l, typename e_access_traits::const_iterator b_r, typename e_access_traits::const_iterator e_r);

      internal_node_pointer
      insert_branch(node_pointer p_left_nd, node_pointer p_right_nd, split_join_branch_bag& r_bag);

      void
      update_min_max_for_inserted_leaf(leaf_pointer p_l);

      void
      erase_leaf(leaf_pointer p_l);

      inline void
      actual_erase_leaf(leaf_pointer p_lf);

      void
      clear_imp(node_pointer p_nd);

      void
      erase_fixup(internal_node_pointer p_nd);

      void
      update_min_max_for_erased_leaf(leaf_pointer p_l);

      static inline const_e_iterator
      pref_begin(const_node_pointer p_nd);

      static inline const_e_iterator
      pref_end(const_node_pointer p_nd);

      inline node_pointer
      find_imp(const_key_reference r_key);

      inline node_pointer
      lower_bound_imp(const_key_reference r_key);

      inline node_pointer
      upper_bound_imp(const_key_reference r_key);

      inline static const_leaf_pointer
      leftmost_descendant(const_node_pointer p_nd);

      inline static leaf_pointer
      leftmost_descendant(node_pointer p_nd);

      inline static const_leaf_pointer
      rightmost_descendant(const_node_pointer p_nd);

      inline static leaf_pointer
      rightmost_descendant(node_pointer p_nd);

#ifdef PB_DS_PAT_TRIE_DEBUG_

      void
      assert_valid() const;

      void
      assert_iterators() const;

      void
      assert_reverse_iterators() const;

      static size_type
      recursive_count_leafs(const_node_pointer p_nd);

#endif // #ifdef PB_DS_PAT_TRIE_DEBUG_

#ifdef PB_DS_PAT_TRIE_TRACE_

      static void
      trace_node(const_node_pointer p_nd, size_type level);

      template<typename Metadata_>
      static void
      trace_node_metadata(const_node_pointer p_nd, type_to_type<Metadata_>);

      static void
      trace_node_metadata(const_node_pointer, type_to_type<null_node_metadata>);

#endif // #ifdef PB_DS_PAT_TRIE_TRACE_

      leaf_pointer
      split_prep(const_key_reference r_key, PB_DS_CLASS_C_DEC& other, split_join_branch_bag& r_bag);

      node_pointer
      rec_split(node_pointer p_nd, const_e_iterator b_it, const_e_iterator e_it, PB_DS_CLASS_C_DEC& other, split_join_branch_bag& r_bag);

      void
      split_insert_branch(size_type e_ind, const_e_iterator b_it, typename internal_node::iterator child_b_it, size_type num_children, split_join_branch_bag& r_bag);

    private:
      static head_allocator s_head_allocator;

      static internal_node_allocator s_internal_node_allocator;

      static leaf_allocator s_leaf_allocator;

      head_pointer m_p_head;

      size_type m_size;
    };

#include <ext/pb_ds/detail/pat_trie_/constructors_destructor_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/iterators_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/insert_join_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/erase_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/find_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/info_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/policy_access_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/split_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/debug_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/trace_fn_imps.hpp>
#include <ext/pb_ds/detail/pat_trie_/update_fn_imps.hpp>

#undef PB_DS_CLASS_C_DEC

#undef PB_DS_CLASS_T_DEC

#undef PB_DS_CLASS_NAME

#undef PB_DS_TYPES_TRAITS_C_DEC

#undef PB_DS_MAP_DEBUG_BASE_C_DEC

#undef PB_DS_V2F
#undef PB_DS_EP2VP
#undef PB_DS_V2S

#undef PB_DS_DBG_ASSERT
#undef PB_DS_DBG_VERIFY
#undef PB_DS_DBG_ONLY

#undef PB_DS_STATIC_ASSERT

  } // namespace detail
} // namespace pb_ds
