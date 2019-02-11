/* { do-go compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_frontend } */

typedef struct { int i; } Foo;
Foo foo;
Foo *bar(void)
{
  return (Foo *)&foo.i;
}

/* { dg-final { scan-tree-dump "&foo;" "gimple" } } */
