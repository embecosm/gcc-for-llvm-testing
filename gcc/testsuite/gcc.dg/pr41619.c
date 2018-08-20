/* { dg-do compile } */
/* { dg-options "-O2 -fno-ira-share-save-slots" } */
/* { dg-require-effective-target gcc_internals } */

struct A {};

int foo();

struct A bar(double x)
{
  double y;
  if (foo())
    y = 1 / x;
  return bar(y);
}
