/* { dg-do compile } */
/* { dg-options "-O -Wmaybe-uninitialized" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int x)
{
  int y;
  if (x)
    return *(&y + 1); /* { dg-bogus "may be used uninitialized" } */
  return 0;
}
