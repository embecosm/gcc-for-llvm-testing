/* { dg-do compile } */
/* { dg-options "-O2 -Wall -Wextra -fdiagnostics-show-caret" } */
/* { dg-require-effective-target gcc_frontend } */

void f (void)
{
  __builtin_printf ("%i", ""); /* { dg-warning "expects argument of type" } */
/* { dg-begin-multiline-output "" }
   __builtin_printf ("%i", "");
                      ~^   ~~
                       |   |
                       int char *
                      %s
   { dg-end-multiline-output "" } */
}
