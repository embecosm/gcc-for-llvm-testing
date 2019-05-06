/* { dg-do compile } */
/* { dg-options "-O" } */
/* { dg-require-effective-target gcc_frontend } */

const short __attribute__((vector_size(16))) y = { 0, 1, 2, 3, 4, 5, 6, 7 };

int
main (int argc, char **argv)
{
  int i = argc;
  y[i] = 7 - i; /* { dg-warning "read-only" } */
  return 0;
}
