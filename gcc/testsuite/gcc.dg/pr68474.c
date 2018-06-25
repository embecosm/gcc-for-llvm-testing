/* { dg-options "-O -funsafe-math-optimizations" } */
/* { dg-require-effective-target builtin_significand } */

long double
foo (long double d1, long double d2)
{
  return d1 || __builtin_significandl (d2);
}
