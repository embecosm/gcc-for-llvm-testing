/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_frontend } */

__GIMPLE() void a()
{
  *0 = 1; /* { dg-error "expected pointer" } */
}
