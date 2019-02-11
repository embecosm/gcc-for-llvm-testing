/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1" } */
/* { dg-require-effective-target gcc_frontend } */

int x;
int foo (int *p)
{
  x = 0;
  if (x)
    *p = 1;
  return x;
}

/* The final load of x should be replaced as well as the
   aliasing store via *p is not reachable.  */

/* { dg-final { scan-tree-dump-not "= x;" "fre1" } } */
