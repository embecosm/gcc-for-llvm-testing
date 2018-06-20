/* { dg-do compile } */
/* { dg-options "-fstrict-overflow -O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

/* Source: Ian Lance Taylor.  Dual of no-strict-overflow-3.c.  */

/* We can only simplify the conditional when using strict overflow
   semantics.  */

int
foo (int i, int j)
{
  return i + 100 < j + 1234;
}

/* { dg-final { scan-tree-dump-not "1234" "optimized" } } */
