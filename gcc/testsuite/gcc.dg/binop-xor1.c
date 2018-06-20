/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized --param logical-op-non-short-circuit=1" } */
/* { dg-require-effective-target gcc_internals } */

int
foo (int a, int b, int c)
{
  return ((a && !b && c) || (!a && b && c));
}

/* { dg-final { scan-tree-dump-times "\\\^" 1 "optimized" } } */
