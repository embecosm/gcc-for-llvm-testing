/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

int foo(int i)
{
  return -i - 5;
}

/* { dg-final { scan-tree-dump "-5 - i" "gimple" } } */
