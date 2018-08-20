/* PR c/71926 */
/* { dg-options "-Wparentheses" }  */
/* { dg-require-effective-target gcc_frontend } */

int
f (void)
{
  int a = 1, b = 2, c = 3, d = 4;
  if (a = 2 || (b != 3 && c != 4 && d != 5)) /* { dg-warning "7:suggest parentheses" } */
    return 1;
  return 0;
}
