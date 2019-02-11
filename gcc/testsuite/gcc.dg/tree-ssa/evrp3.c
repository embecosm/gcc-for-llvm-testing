/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-evrp" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int i);
void bar (int j)
{
  unsigned int i;
  for (i = 0; i < 10; ++i)
    {
      bar (i + 1);
    }
}

/* { dg-final { scan-tree-dump "\\\[1, 10\\\]" "evrp" } } */

