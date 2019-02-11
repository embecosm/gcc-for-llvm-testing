/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int i)
{
  int a[16];
  __builtin_memset (a, 42, sizeof (a));
  return a[i];
}

/* { dg-final { scan-tree-dump "return 707406378;" "fre1" { target { int32plus } } } } */
