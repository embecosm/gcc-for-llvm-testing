/* { dg-do compile } */
/* { dg-options "-O -fgimple" } */
/* { dg-require-effective-target gcc_internals } */

void __GIMPLE (startwith ("ccp1")) foo ()
{
  int a;
  int b;
  a = b + 2;
  return;
}
