/* PR target/79494 */
/* { dg-do compile } */
/* { dg-require-effective-target split_stack } */
/* { dg-require-effective-target nested_func } */
/* { dg-options "-O2 -fsplit-stack -g" } */

void
foo (int a)
{
  __label__ lab;
  __attribute__((noinline, noclone)) void bar (int b)
  {
    switch (b)
      {
      case 1:
	goto lab;
      case 2:
	goto lab;
      }
  }
  bar (a);
lab:;
}
