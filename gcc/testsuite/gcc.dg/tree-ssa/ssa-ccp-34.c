/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-ccp1" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int x)
{
  int y = 0;
  int z = x + 1;
  return z + y;
}

/* { dg-final { scan-tree-dump-times "\\+" 1 "ccp1" } } */
