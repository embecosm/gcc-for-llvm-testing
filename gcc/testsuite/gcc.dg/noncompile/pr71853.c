/* PR c/71853 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void f (void)
{
  case (0) { /* { dg-error "expected" } */
    switch 0: { } /* { dg-error "expected" } */
  }
}
