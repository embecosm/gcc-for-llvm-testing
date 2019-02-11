/* { dg-do compile } */
/* { dg-options "-O3 -fdump-tree-ldist-details" } */
/* { dg-require-effective-target gcc_frontend } */

void bar(char *p, int n)
{
  int i;
  for (i = 1; i < n; i++)
    p[i-1] = p[i];
}

/* { dg-final { scan-tree-dump "generated memmove" "ldist" } } */
