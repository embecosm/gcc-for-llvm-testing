/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
flarm(void)
{
  static void foo();  /* { dg-error "invalid storage class" } */

  foo();
}
