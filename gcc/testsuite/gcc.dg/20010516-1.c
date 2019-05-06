/* { dg-options "-fshow-column" } */
/* { dg-require-effective-target gcc_frontend } */

void
foo()
{
      char d;
      __asm volatile ( "" :: "m"(&d)); /* { dg-error "34:" "non-lvalue" } */
}
