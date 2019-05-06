/* { dg-do compile } */
/* { dg-options "-pedantic-errors" } */
/* { dg-require-effective-target gcc_frontend } */

void f (int, ...);

int
f1 (void)
{
  int (*x) ();
  x = f; /* { dg-error "assignment to 'int \\(\\*\\)\\(\\)' from incompatible pointer type 'void \\(\\*\\)\\(int,  \.\.\.\\)'" } */
  return x (1);
}
