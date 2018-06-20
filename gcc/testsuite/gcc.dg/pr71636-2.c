/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-forwprop-details" } */
/* { dg-require-effective-target gcc_internals } */

unsigned f(unsigned x, unsigned b)
{
  unsigned t1 = 1U << b;
  unsigned t2 = t1 - 1;
  unsigned t3 = x & t2;
  return t3;
}

/* { dg-final { scan-tree-dump "_\[0-9\] = ~_\[0-9\]" "forwprop1" } } */
