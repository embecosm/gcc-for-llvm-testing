/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-pre-details -fno-tree-loop-im" } */
/* { dg-require-effective-target gcc_frontend } */

struct Bar { int a; int b; };
struct Foo { int x; struct Bar y; };

int __attribute__((const)) foo (struct Bar);

int bar (int b)
{
  struct Foo f;
  int c;
  while (b--)
    {
      c = foo(f.y);
    }
  return c;
}

/* { dg-final { scan-tree-dump "Replaced foo \\(f.y\\)" "pre" } } */
