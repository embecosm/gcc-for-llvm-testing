/* PR middle-end/40943 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wuninitialized" } */

void
foo (void)
{
  int *p;
  *p = 3;	/* { dg-warning "is used uninitialized" } */
}
