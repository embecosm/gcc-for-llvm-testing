/* { dg-do compile } */
/* { dg-options "-fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

void foo (void)
{
  int a;

  void bar (void)
  {
    a = 1;
  }
}

/* { dg-final { scan-tree-dump-not "bar" "optimized" } } */
