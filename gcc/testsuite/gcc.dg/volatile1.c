/* PR c/12553: we were erroneously setting TREE_SIDE_EFFECTS on &y, which
   confused tree-ssa.  */
/* { dg-additional-options "-Wno-unused-comparison" } */

void f()
{
  int x;
  volatile int y;
  &x == &y;
}
