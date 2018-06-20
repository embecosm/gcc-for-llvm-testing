/* PR c/77490 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wall" } */

int
fn (_Bool b)
{
  int r = 0;

  r += b++; /* { dg-warning "increment of a boolean expression" } */
  r += ++b; /* { dg-warning "increment of a boolean expression" } */
  r += b--; /* { dg-warning "decrement of a boolean expression" } */
  r += --b; /* { dg-warning "decrement of a boolean expression" } */

  return r;
}
