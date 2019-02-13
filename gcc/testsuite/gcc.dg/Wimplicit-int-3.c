/* { dg-do compile } */
/* { dg-options "-pedantic-errors -Wno-implicit-int" } */
/* { dg-additional-options "-Wno-return-type" } */

static l;

foo (a)
{
  auto p;
  typedef bar;
}
