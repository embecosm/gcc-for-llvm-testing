/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

int x;
void
foo (void)
{
  if (x == 0)
    x = 0;
}
void
bar (int i)
{
  if (x == i)
    x = i;
}

/* { dg-final { scan-tree-dump-not "x =" "optimized" } } */
