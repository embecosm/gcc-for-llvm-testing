/* PR target/85430 */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-tree-ccp -fno-tree-fre" } */
/* { dg-require-effective-target gcc_frontend } */

typedef char V __attribute__((vector_size (4)));

V
foo (V v)
{
  v[(V){}[0]] <<= 1;
  return v;
}
