/* { dg-error "expected declaration or statement" "" { target *-*-* } 0 } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
     __PRETTY_FUNCTION__;
