/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple -fwrapv" } */
/* { dg-require-effective-target gcc_frontend } */
int g(int x)
{
   return (x - 10) < 0;
}
/* There should be no x >= 9 and one x - 10. */
/* { dg-final { scan-tree-dump-times "<= 9" 0 "gimple"} } */
/* { dg-final { scan-tree-dump-times "\\+ -10" 1 "gimple"} } */
