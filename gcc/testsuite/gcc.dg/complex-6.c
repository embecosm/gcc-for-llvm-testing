/* PR tree-optimization/70291.  */

/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-cplxlower" } */
/* { dg-require-effective-target gcc_frontend } */

__complex float
foo (__complex float a, __complex float b)
{
  return a * b;
}

/* { dg-final { scan-tree-dump-times "unord" 1 "cplxlower1" } } */
/* { dg-final { scan-tree-dump-times "__mulsc3" 1 "cplxlower1" } } */
