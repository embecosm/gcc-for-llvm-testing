/* PR c/28649 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  +;  /* { dg-error "expected expression" } */
}

int i;

void bar()
{
  i++;  /* { dg-bogus "undeclared" } */
}
