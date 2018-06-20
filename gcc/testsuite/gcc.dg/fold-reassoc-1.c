/* { dg-do compile } */
/* { dg-options "-O -ffast-math -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

double foo (double x)
{
  return (x + 0.5 - x - 0.5);
}

/* { dg-final { scan-tree-dump "return 0.0;" "original" } } */
