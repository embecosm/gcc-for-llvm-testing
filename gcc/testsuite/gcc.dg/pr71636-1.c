/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

unsigned f(unsigned x, unsigned b)
{
  return x & ((1U << b) - 1);
}

/* { dg-final { scan-tree-dump-not "1 <<" "gimple" } } */
