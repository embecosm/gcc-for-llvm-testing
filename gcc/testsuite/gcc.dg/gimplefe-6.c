/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

void __GIMPLE () foo ()
{
  int a;
  int b;
  int c;
  int d;

bb_2:
  a = ~b;
  b = a << c;
  c = a & b;
  d = b | c;

bb_3:
  return;
}
