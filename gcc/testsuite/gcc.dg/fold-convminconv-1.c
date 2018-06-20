/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

int foo (unsigned short a[], unsigned int x)
{
  unsigned int i;
  for (i = 0; i < 1000; i++)
    {
      x = a[i];
      a[i] = (x >= 255 ? 255 : x);
    }
  return x;
}

/* { dg-final { scan-tree-dump-not " = MIN_EXPR <x_\[0-9\]*" "optimized" } } */
