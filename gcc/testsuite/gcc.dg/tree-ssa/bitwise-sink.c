/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

int
foo (_Bool x)
{
  return (x ^ 1);
}

/* { dg-final { scan-tree-dump-times "~x" 1 "optimized" } } */
