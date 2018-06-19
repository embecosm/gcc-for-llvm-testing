/* { dg-do compile } */
/* { dg-options "-O -Winline" } */
/* { dg-require-effective-target nested_func } */

static inline int foo1 (int a)
{                       /* { dg-bogus "function not inlinable" } */
  void bar1 (int b)
  {}
  return a;
}

int foo2 (int a)
{
  return foo1 (a);
}
