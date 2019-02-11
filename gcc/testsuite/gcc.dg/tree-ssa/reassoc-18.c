/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-reassoc1" } */
/* { dg-require-effective-target gcc_frontend } */

unsigned int
ETree_nFactorEntriesInFront (unsigned int b, unsigned int m)
{
  unsigned int nent = b*b + 2*b*m;
  return nent;
}

/* { dg-final { scan-tree-dump-times "\\\*" 2 "reassoc1" } } */
