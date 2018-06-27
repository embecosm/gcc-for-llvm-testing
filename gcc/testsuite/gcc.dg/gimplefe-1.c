/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

int i;
void __GIMPLE foo()
{
  i = 1;
}
