/* { dg-do compile } */
/* { dg-options "-O2 -ftree-tail-merge -fdump-tree-pre" } */
/* { dg-require-effective-target gcc_internals } */

int z;

void
foo (int y)
{
  if (y == 6)
    z = 5;
  else
    z = 5;
}

/* { dg-final { scan-tree-dump-times "z = 5" 1 "pre"} } */
