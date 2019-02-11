/* { dg-do compile } */
/* { dg-options "-Ofast -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

float
foo (float a)
{
  float tmp = 1.0f / __builtin_sqrtf (a);
  return a * tmp;
}

/* { dg-final { scan-tree-dump-not " / " "optimized" } } */
