/* PR c/71266 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int fn1 (a)
  enum b {  /* { dg-warning "empty declaration" } */
    a /* { dg-error ".a. declared as a non-parameter" } */
  };
{
}
