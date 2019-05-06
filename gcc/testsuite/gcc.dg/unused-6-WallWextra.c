/* PR 28875 */
/* { dg-do compile } */
/* { dg-options "-O3 -Wextra -Wall" } */
static int t(int i) /* { dg-warning "unused parameter" "unused parameter warning" } */
/* { dg-require-effective-target gcc_frontend } */
{
  return 0;
}
int tt()
{
  return t(0);
}
