/* { dg-do compile } */
/* { dg-options "-O3 -Warray-bounds -fdump-tree-cunroll-blocks-details" } */
/* { dg-require-effective-target gcc_frontend } */
struct a {int a[8];int b;};
void
t(struct a *a)
{
  for (int i=0;a->a[i];i++)
    a->a[i]++;
}
/* { dg-final { scan-tree-dump-times "loop with 6 iterations completely unrolled" 1 "cunroll" } } */
/* { dg-final { scan-tree-dump-not "Invalid sum" "cunroll" } } */
