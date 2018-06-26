/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -fno-tree-forwprop -fno-tree-reassoc" } */
/* { dg-options "-O2 -ffast-math -fno-tree-forwprop -fno-tree-reassoc -mfma4" { target x86_64-*-* i?86-*-* } } */
/* { dg-require-effective-target gcc_internals } */

float
foo (float x, float cim)
{
  float c = x * cim;
  float d = -c;
  return c - d;
}
