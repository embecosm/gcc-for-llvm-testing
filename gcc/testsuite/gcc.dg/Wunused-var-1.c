/* { dg-do compile } */
/* { dg-options "-Wunused" } */
/* { dg-require-effective-target nested_func } */

int
f1 (void)
{
  int a;
  int foo (void)
  {
    return a;
  }
  a = 1;
  return foo ();
}

void
f2 (void)
{
  int a;	/* { dg-warning "set but not used" } */
  void foo (void)
  {
    a = 2;
  }
  a = 1;
  foo ();
}
