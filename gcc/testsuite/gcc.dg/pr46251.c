/* { dg-do compile } */
/* { dg-options "-ffast-math" } */
/* { dg-require-effective-target builtin_sincos } */

void foo (long double *x)
{
  __builtin_sincosl (*x, x, x);
}
