/* { dg-do compile } */
/* { dg-options "-fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

int bar(char p1, char p2)
{
  return &p1 == &p2;
}

/* { dg-final { scan-tree-dump "return 0;" "original" } } */
