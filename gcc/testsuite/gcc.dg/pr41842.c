/* PR c/41842 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
f ()
{
  char x[g (h)];	/* { dg-error "undeclared" } */
/* { dg-message "undeclared identifier is reported only once" "reminder" { target *-*-* } .-1 } */
}
