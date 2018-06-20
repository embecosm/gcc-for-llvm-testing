/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wstrict-overflow=4" } */

int
f (int i)
{
  return __builtin_abs (i * i); /* { dg-warning "assuming signed overflow" } */
}
