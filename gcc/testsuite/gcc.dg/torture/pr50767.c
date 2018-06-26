/* { dg-do compile } */
/* { dg-options "-fno-tree-copy-prop -fno-tree-dominator-opts" } */
/* { dg-require-effective-target gcc_internals } */

struct S
{
  struct S *s;
};

static struct S *ss;
struct S *s;

void bar(void);

void foo(void)
{
  for (;;)
    {
      s->s = ss;
      bar ();
    }
}
