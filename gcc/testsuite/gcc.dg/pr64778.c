/* PR c/64778 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int
foo (int p)
{
  int a;
  a ^= foo (,);	/* { dg-error "expected expression before|too many arguments" } */
  return a;
}
