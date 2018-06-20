/* PR 23722 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fsyntax-only" } */
int f()
{
  if (1)
  {
   return 1;
  else /* { dg-error "expected .\}. before 'else'" } */
  {
  }
}
