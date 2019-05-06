/* PR c/35443 */
/* { dg-options "" } */
/* { dg-bogus "not supported by" "" { target *-*-* } 0 } */
/* { dg-require-effective-target gcc_frontend } */

void
foo ()
{
  ({ int i; i; })();	/* { dg-error "is not a function" } */
}
