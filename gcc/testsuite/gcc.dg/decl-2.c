/* PR c/7411 */
/* Contributed by Christian Ehrhardt */
/* Added extra line-breaks to check that diagnostics refer to correct token.
   --Per Bothner. */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo(void)
{
  char
    c	/* { dg-message "note: previous declaration" } */
    ;
  int i;
  int
    c	/* { dg-error "conflicting types" } */
    = i;
}
