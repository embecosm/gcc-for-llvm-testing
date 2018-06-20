/* { dg-do compile } */
/* { dg-options "-O -fgimple -fdump-tree-ssa-gimple" } */
/* { dg-require-effective-target gcc_internals } */

int __GIMPLE() f(int a)
{
  int t0;
  t0_1 = __ABS a;
  return t0_1;
}

/* { dg-final { scan-tree-dump "__ABS a" "ssa" } } */
