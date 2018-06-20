/* { dg-do compile } */
/* { dg-options "-fwrapv -fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */
int f (int i)
{
  return (i - 2) > i;
}

int g (int i)
{
  return (i + 2) < i;
}

int h (double i)
{
  return (i + 2.0) <= i;
}
/* { dg-final { scan-tree-dump-times " = 0" 0 "gimple" } } */
