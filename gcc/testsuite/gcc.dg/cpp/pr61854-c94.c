/* PR c/61854 */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:199409" } */

void
foo (void)
{
  // 1st
  /* { dg-error "C\\+\\+ style comments are not allowed in ISO C90" "comments"  { target *-*-*} .-1 } */
  /* { dg-error "reported only once" ""  { target *-*-*} .-2 } */
  // 2nd
  // 3rd
}
