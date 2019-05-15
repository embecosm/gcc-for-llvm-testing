/* PR c/36299 */
/* { dg-do compile } */
/* { dg-options "-Waddress" } */
/* { dg-additional-options "-Wno-tautological-pointer-compare" } */

int
foo(void)
{
  char a[1];
  return a == 0;
}
