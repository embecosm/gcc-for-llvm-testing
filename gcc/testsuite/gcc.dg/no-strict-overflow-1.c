/* { dg-do compile } */
/* { dg-options "-fno-strict-overflow -O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

/* Source: Ian Lance Taylor.  Dual of strict-overflow-1.c.  */

/* We can only simplify the conditional when using strict overflow
   semantics.  */

int
foo (int i)
{
  return i - 5 < 10;
}

/* { dg-final { scan-tree-dump "-[ ]*5" "optimized" } } */
