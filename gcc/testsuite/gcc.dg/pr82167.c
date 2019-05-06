/* PR c/82167 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
fn1 (int a[])
{
  __builtin_printf ("%zu\n", sizeof (*&a)); /* { dg-warning ".sizeof. on array function parameter .a. will return size of .int \\*." } */
}

void
fn2 (int *a[])
{
  __builtin_printf ("%zu\n", sizeof (*&a)); /* { dg-warning ".sizeof. on array function parameter .a. will return size of .int \\*\\*." } */
}
