/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

int __GIMPLE foo(int a)
{
  int t1;
  t1_1 = __builtin_abs (a);
  return t1_1;
}
