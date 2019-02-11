/* PR middle-end/84309 */
/* { dg-do compile } */
/* { dg-options "-Ofast -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

double
foo (double x)
{
  return __builtin_pow (2.0, x);
}

/* { dg-final { scan-tree-dump "__builtin_exp2 " "optimized" { target *-*-linux* *-*-gnu* } } } */
