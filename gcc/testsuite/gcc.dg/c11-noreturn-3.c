/* Test C11 _Noreturn.  Test _Noreturn on main, hosted.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c11 -pedantic-errors -fhosted" } */

_Noreturn void exit (int);

_Noreturn int
main (void) /* { dg-error "'main' declared '_Noreturn'" } */
{
  exit (0);
}
