/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

int foo(int i)
{
  return i - -1;
}

/* { dg-final { scan-tree-dump "i \\+ 1" "gimple" } } */
