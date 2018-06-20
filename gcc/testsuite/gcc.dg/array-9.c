/* PR target/27421 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct A
{
  int i;
  void x[1];  /* { dg-error "array of voids" } */
};

void foo(struct A a) {}
