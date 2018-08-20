/* PR middle-end/57251 */
/* { dg-do compile } */
/* { dg-options "-ftracer" } */
/* { dg-require-effective-target gcc_internals } */

short a, b;
int
f (void)
{
  long long i = 2;
  a ? f () ? : 0 : b--;
  b &= i *= a |= 0;
}
