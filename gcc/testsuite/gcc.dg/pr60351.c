/* PR c/60351 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
f (int i)
{
  i >> -1; /* { dg-warning "5:right shift count is negative" } */
  i >> 250; /* { dg-warning "5:right shift count >= width of type" } */
  i << -1; /* { dg-warning "5:left shift count is negative" } */
  i << 250; /* { dg-warning "5:left shift count >= width of type" } */
}
