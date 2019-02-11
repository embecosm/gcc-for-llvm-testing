/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1" } */
/* { dg-require-effective-target gcc_frontend } */

int x;
int foo (void)
{
  x = 1;
  return __builtin_ffs (x);
}

/* { dg-final { scan-tree-dump-not "ffs" "fre1" } } */
