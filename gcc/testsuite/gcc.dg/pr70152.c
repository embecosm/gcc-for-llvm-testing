/* PR tree-optimization/70152 */
/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-builtin-requires-header" } */

int a;
int foo (void);
int setjmp (char *);
char buf[64];

static int
bar (int x)
{
  x = 0;
  setjmp (buf);
  for (;;)
    {
    switch (x)
      case 5:
	x = foo ();
    }
}

void
baz (void)
{
  bar (a);
}
