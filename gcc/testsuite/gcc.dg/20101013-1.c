/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

int foo(int a)
{
  int x = (a & (~15)) / 16;
  return x;
}

/* { dg-final { scan-tree-dump ">>" "optimized" } } */
