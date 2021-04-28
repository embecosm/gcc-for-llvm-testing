/* { dg-do compile } */
/* { dg-additional-options "-fexcess-precision=fast -O1 -fdump-tree-optimized" } */
/* { dg-require-effective-target-flag { -fdump-tree-optimized -fexcess-precision=fast } } */
void foo (float a, float b, float *c)
{
  double e = (double)a * (double)b;
  *c = (float)e;
}

/* { dg-final { scan-tree-dump-not {double} "optimized" } } */
