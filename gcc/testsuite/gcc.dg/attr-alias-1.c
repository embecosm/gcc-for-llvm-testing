/* PR c++/12795 */
/* { dg-require-alias "" } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  extern void bar () __attribute__ ((__alias__ ("BAR"))); /* { dg-warning "ignored" } */
  bar ();
}
