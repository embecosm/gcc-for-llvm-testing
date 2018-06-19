/* PR middle-end/71476 */
/* { dg-do compile } */
/* { dg-options "-Wswitch-unreachable" } */
/* { dg-require-effective-target nested_func } */

void
foo (int a)
{
  switch (a)
    {
      void f (void) { }
    }
}
