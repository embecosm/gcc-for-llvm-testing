/* { dg-do compile } */
/* { dg-options "-O -ftrapping-math -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-require-effective-target builtin_isnan } */

int f (double d)
{
  return !__builtin_isnan (d);
}

/* { dg-final { scan-tree-dump " ord " "optimized" } } */
