/* PR c/85045 */
/* { dg-do compile } */
/* { dg-options "-fno-diagnostics-show-caret" } */
/* { dg-require-effective-target gcc_frontend } */

void
f (double a, double b)
{
  (a / b) (); /* { dg-error "called object .a / b. is not a function or function pointer" } */
}
