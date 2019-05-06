/* PR c/66415 */
/* { dg-do compile } */
/* { dg-options "-Wformat" } */
/* { dg-require-effective-target gcc_frontend } */

#24
void
fn1 (void)
{
  __builtin_printf                                ("xxxxxxxxxxxxxxxxx%dxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
  /* { dg-warning "format" "" { target *-*-* } 27 } */
}
