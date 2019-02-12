/* PR middle-end/60534 */
/* { dg-do compile } */
/* { dg-options "-fopenmp -O -fno-tree-loop-optimize" } */
/* { dg-require-effective-target gcc_frontend } */

extern int d[];

int
foo (int a)
{
  int c = 0;
  int l;
#pragma omp simd reduction(+: c)
  for (l = 0; l < a; ++l)
    c += d[l];
  return c;
}
