/* PR c/36299 */
/* { dg-do compile } */
/* { dg-options "-Waddress" } */
/* { dg-additional-options "-Wno-tautological-constant-out-of-range-compare" } */

int
foo(void)
{
  char a[1];
  return a == 0;
}
