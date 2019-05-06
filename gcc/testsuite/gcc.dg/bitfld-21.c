/* Test for bit-field widths not integer constant expressions but
   folding to integer constants: PR 42439.  */
/* { dg-do compile } */
/* { dg-options "-O2 -pedantic-errors" } */
/* { dg-require-effective-target gcc_frontend } */

void
f (void)
{
  const int m = 1;
  ((void)(sizeof(struct { int i:!!m; }))); /* { dg-error "not an integer constant expression" } */
}
