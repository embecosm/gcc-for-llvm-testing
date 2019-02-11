/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-ccp2" } */
/* { dg-require-effective-target gcc_frontend } */

static double num;
int foo (void)
{
  return *(unsigned *)&num;
}

/* { dg-final { scan-tree-dump "return 0;" "ccp2" } } */
