/* PR c/27721 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  int i();
  i += 0;  /* { dg-error "lvalue required" } */
}
