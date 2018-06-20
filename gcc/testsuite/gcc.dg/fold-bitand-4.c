/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

int foo (int i)
{
  return (i * 8) & 5;
}

unsigned bar (unsigned i)
{
  return (i * 6) & 5;
}

/* { dg-final { scan-tree-dump-times "\\\&" 1 "original" } } */
/* { dg-final { scan-tree-dump-times "\\\& 4;" 1 "original" } } */
