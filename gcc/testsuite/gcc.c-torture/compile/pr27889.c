/* { dg-require-effective-target trampolines } */
/* { dg-require-effective-target nested_func } */

void h(void (*)(void));
_Complex int g (void)
{
  _Complex int x;
  void f(void)
  {
     x = x + x;
  }
  h(f);
  return x;
}
