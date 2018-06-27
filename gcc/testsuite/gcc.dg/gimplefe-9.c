/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

int __GIMPLE() bar()
{
  int a;
  a = a + 1;
  return a;
}

void __GIMPLE() foo()
{
  int b;
  b = bar();
}
