/* PR target/48767 */
/* { dg-require-effective-target gcc_frontend } */

void
foo (__builtin_va_list ap)
{
  __builtin_va_arg (ap, void); /* { dg-error "second argument to .va_arg. is of incomplete type .void." } */
}
