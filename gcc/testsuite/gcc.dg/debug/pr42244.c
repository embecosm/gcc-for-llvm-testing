/* PR debug/42444 */
/* { dg-do compile } */
/* { dg-options "-O2 -g -fmodulo-sched -ffloat-store" } */
/* { dg-require-effective-target gcc_internals } */

extern int a, b;

double
foo (double x)
{
  for (; a > b; a--)
    x *= (double) a;
  return x;
}
