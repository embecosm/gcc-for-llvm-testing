/* PR middle-end/85195 */
/* { dg-do compile { target int128 } } */
/* { dg-require-effective-target return_vector } */
/* { dg-options "-Wno-psabi -O -fno-tree-ccp" } */
/* { dg-require-effective-target gcc_frontend } */

typedef __int128 V __attribute__ ((vector_size (16)));

extern int bar (V);

V v;
int i;

V
foo (void)
{
  do
    v *= bar (v & i);
  while ((V){}[0]);
  return v;
}
