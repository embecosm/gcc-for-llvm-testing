/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

int foo (int i)
{
  return (i + 2) - (i + 1);
}
int bar (int i)
{
  return (i + 2) + ~i;
}

/* { dg-final { scan-tree-dump-times "return 1;" 2 "original" } } */
