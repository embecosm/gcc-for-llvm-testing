/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

long foo(long n, long m)
{
  return n - (n / m) * m;
}

/* { dg-final { scan-tree-dump "n % m" "gimple" } } */
