/* PR c/81289 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int
fn (int mm)
{
  mm == *&&
} /* { dg-error "expected identifier" } */
