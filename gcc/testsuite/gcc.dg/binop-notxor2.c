/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

int
foo (_Bool a, _Bool b)
{
  return (a ^ (a == 0)) | ((b == 0) ^ b);
}

/* { dg-final { scan-tree-dump-times "return 1" 1 "optimized" } } */
