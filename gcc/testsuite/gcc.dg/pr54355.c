/* PR c/54355 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
foo (int i)
{
  switch (i)
  {
  case 0: T x > /* { dg-error "(label|unknown type|expected)" } */
  }
} /* { dg-error "expected" } */
