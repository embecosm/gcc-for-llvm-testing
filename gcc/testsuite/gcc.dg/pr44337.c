/* PR middle-end/44337 */
/* { dg-do compile } */
/* { dg-options "-O -fno-tree-dce -fno-tree-dse -w" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (void)
{
  _Complex float v[1];
  v[1] = 0;
}
