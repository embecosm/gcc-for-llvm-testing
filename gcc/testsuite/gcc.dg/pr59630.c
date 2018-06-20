/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O" } */

_Bool foo()
{
  _Bool (*f)(int) = __builtin_abs; /* { dg-warning "" } */
  return f(0);
}
