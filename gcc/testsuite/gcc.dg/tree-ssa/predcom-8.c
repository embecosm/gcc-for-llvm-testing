/* { dg-do compile } */
/* { dg-options "-O3 -fdump-tree-pcom-details" } */
/* { dg-require-effective-target gcc_frontend } */

int is_sorted(int *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
      return 0;
  return 1;
}

/* { dg-final { scan-tree-dump "Executing predictive commoning without unrolling" "pcom" } } */
