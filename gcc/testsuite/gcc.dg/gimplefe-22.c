/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

void __GIMPLE ()
foo (short * p)
{
  *p = _Literal (short int) 1;
  return;
}
