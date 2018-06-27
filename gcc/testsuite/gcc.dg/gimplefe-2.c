/* { dg-do compile }*/
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

int a;
void __GIMPLE () foo ()
{
  int b;
  b = a;
  b = b + 1;
  a = b;
}
