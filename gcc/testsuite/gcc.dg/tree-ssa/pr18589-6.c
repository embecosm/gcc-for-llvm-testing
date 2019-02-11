/* { dg-do compile } */
/* { dg-options "-O3 -ffast-math -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

double baz (double x, double y)
{
  return __builtin_pow (x, 3.0) * __builtin_pow (y, 4.0);
}

/* { dg-final { scan-tree-dump-times " \\* " 4 "optimized" } } */
