/* { dg-do compile } */
/* { dg-options "-O3 -ffast-math -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

long double baz (long double x, long double y)
{
  return x * x * x * x * y * y * y * y;
}

/* { dg-final { scan-tree-dump-times " \\* " 3 "optimized" } } */
