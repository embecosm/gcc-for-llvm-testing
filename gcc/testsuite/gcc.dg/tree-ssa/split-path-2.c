/* { dg-do compile } */
/* { dg-options "-O2 -fsplit-paths -fdump-tree-split-paths-details " } */
/* { dg-require-effective-target gcc_frontend } */

int
foo(signed char *p, int n)
{
  int s = 0;
  int i;

  for (i = 0; i < n; i++) {
    if (p[i] >= 0)
      s++;
    else
      s--;
  }

  return s;
}

/* { dg-final { scan-tree-dump "appears to be a join point for if-convertable diamond" "split-paths" } } */

