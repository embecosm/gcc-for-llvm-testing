/* PR debug/46171 */
/* { dg-do compile } */
/* { dg-options "-O -fno-tree-dce -g" } */
/* { dg-require-effective-target gcc_internals } */

double bard ();
float barf (float);

void
foo (float f)
{
  f = barf (f);
  double d = bard ();
}
