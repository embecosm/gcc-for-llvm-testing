
/* { dg-do compile } */
/* { dg-options "-O3 -Wunused-parameter" } */
/* { dg-require-effective-target gcc_frontend } */
static int t(int i) /* { dg-warning "unused parameter" "unused parameter warning" } */
{
  return 0;
}
int tt()
{
  return t(0);
}
