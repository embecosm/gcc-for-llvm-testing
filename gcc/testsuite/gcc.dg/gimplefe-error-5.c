/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_frontend } */

__GIMPLE() void a()
{
  __MEM() = 0; /* { dg-error "expected .<." } */
}
