/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target gcc_frontend } */

int
foo (int *p)
{
  *p = 0;
  return *p;
}

/* The store to *p should be propagated to the load statement.  */
/* { dg-final { scan-tree-dump "Replaced \\\*p_.\\\(D\\\) with 0" "fre1" } } */
