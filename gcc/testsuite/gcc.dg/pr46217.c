/* { dg-do compile } */
/* { dg-options "-O3 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */

int foo(int a)
{
  int t;
  *(volatile int *)&t = a;
}

/* { dg-final { scan-tree-dump "={v}" "optimized" } } */
