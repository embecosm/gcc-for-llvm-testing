/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-cddce1" } */
/* { dg-require-effective-target gcc_internals } */

int *
fx (int *a, int sz)
{
  int *b = a + sz;
  b = b - sz;
  /* forwprop together with FRE should optimize this to return a;  */
  return b;
}

/* { dg-final { scan-tree-dump "return a" "cddce1" } } */
