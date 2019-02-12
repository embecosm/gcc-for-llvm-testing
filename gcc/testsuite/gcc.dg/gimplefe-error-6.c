/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_frontend } */

void a(int);

__GIMPLE() void b()
{
  a_2 = 0; /* { dg-error "invalid" } */
}
