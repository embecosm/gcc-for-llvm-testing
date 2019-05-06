/* PR c/83595 */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

void
foo ()
{
  (())((int){0);	/* { dg-error "expected expression before" } */
}
