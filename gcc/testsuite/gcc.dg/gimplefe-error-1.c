/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-options "-fgimple" } */

void __GIMPLE () foo (int a)
{
bb_2:
  a = *b; /* { dg-error "undeclared" } */

bb_3:
  return;
}
