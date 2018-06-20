/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

#include <math.h>

double t (double x)
{
 x = -x;
 x = cos (x);
 x = -x;
 x = cosh (x);
 return x;
}

/* { dg-final { scan-tree-dump-not "-x" "optimized" } } */

