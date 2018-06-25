/* { dg-do compile } */
/* { dg-options "-Os -ffast-math" } */
/* { dg-require-effective-target noclone } */

extern int ilogbl(long double);
extern int printf(const char *format, ...);

__attribute__((noinline, noclone))
int foo(long double x)
{
  return ilogbl(x);
}

int main()
{
  printf("%d\n", foo(100));
  return 0;
}
