/* { dg-do compile } */
/* { dg-options "-fdump-tree-ssa" } */
/* { dg-require-effective-target gcc_internals } */

volatile int *q;
void foo(int i)
{
  volatile int a[2];
  volatile int *p = &a[i];
  q = p;
}

/* { dg-final { scan-tree-dump-not "{v}" "ssa" } } */
