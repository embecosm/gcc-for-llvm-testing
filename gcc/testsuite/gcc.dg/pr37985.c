/* PR c37985 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options " -Wall -Wextra " } */
unsigned char foo(unsigned char a)
{
  a >> 2; /* { dg-warning "no effect" } */
  return a;
}
