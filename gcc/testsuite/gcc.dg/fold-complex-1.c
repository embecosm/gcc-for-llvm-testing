/* { dg-do compile } */
/* { dg-options "-O -ffast-math -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

_Complex float
foo (_Complex float x)
{
  return  __real x + 1.0iF * __imag x;
}

/* { dg-final { scan-tree-dump-times "COMPLEX_EXPR" 0 "original" } } */
