/* { dg-options "-O -fexpensive-optimizations -fno-tree-bit-ccp" } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-require-effective-target noclone } */

__attribute__ ((noinline, noclone))
int
foo (unsigned short x, unsigned short y)
{
  int r;
  if (__builtin_mul_overflow (x, y, &r))
    __builtin_abort ();
  return r;
}

int
main (void)
{
  int x = 1;
  int y = 2;
  if (foo (x, y) != x * y)
    __builtin_abort ();
  return 0;
}

