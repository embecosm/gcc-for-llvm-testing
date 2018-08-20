/* { dg-do compile } */
/* { dg-additional-options "-ffast-math -frounding-math" } */
/* { dg-require-effective-target gcc_internals } */

float
foo (void)
{
  return 1.1f + 2.2f + 2.2f;
}
