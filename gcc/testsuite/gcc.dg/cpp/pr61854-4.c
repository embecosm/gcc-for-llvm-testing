/* PR c/61854 */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c89" } */

void
foo (void)
{
#if 0
  // Do not error here.
#endif
#if 1
  // But error here.
#endif
  /* { dg-error "C\\+\\+ style comments are not allowed in ISO C90" "comments"  { target *-*-*} 13 } */
  /* { dg-message "note: \[^\n\r]*reported only once" ""  { target *-*-*} 13 } */
}
