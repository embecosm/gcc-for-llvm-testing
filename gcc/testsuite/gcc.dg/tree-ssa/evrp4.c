/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-evrp" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int *p);

struct st
{
  int a;
  int b;
};

int bar (struct st *s)
{

  if (!s)
    return 0;
  foo (&s->a);
}

/* { dg-final { scan-tree-dump "\~\\\[0B, 0B\\\]" "evrp" } } */
