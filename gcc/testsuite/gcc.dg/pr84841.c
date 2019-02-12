/* PR tree-optimization/84841 */
/* { dg-do compile } */
/* { dg-options "-O2 -fassociative-math -frounding-math -fno-signed-zeros -fno-trapping-math -fno-tree-forwprop" } */
/* { dg-require-effective-target gcc_frontend } */

double
foo (double x)
{
  return -x * 0.1 * 0.1;
}
