/* PR c/61852 */
/* { dg-do compile } */
/* { dg-options "-Wimplicit-function-declaration" } */
/* { dg-require-effective-target gcc_frontend } */

int
f (int a)
{
  int b = a + a + a + ff (a); /* { dg-warning "23:implicit declaration of function" } */
  return b;
}
