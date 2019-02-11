/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-require-effective-target gcc_frontend } */

int main()
{
  int *p = __builtin_malloc (4);
  *p = 4;
  return 0;
}

/* { dg-final { scan-tree-dump-not "malloc" "optimized" } } */
