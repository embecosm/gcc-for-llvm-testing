/* PR tree-optimization/56350 */
/* { dg-do compile } */
/* { dg-options "-O -ftree-vectorize" } */
/* { dg-require-effective-target gcc_internals } */

int a, b, c;

void
f (void)
{
  for (; c; c++)
    for (b = 0; b < 2; b++)
      a /= 8;
}
