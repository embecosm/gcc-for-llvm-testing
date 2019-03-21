/* PR target/84710 */
/* { dg-do compile } */
/* { dg-options "-O -fno-forward-propagate" } */
/* { dg-require-effective-target gcc_frontend } */

char a;
int b;

void
foo (void)
{
  int d;
  b = __builtin_mul_overflow ((char) d, 0xfe, &a);
}
