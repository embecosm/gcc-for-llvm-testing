/* { dg-do compile } */
/* { dg-require-effective-target return_vector } */
/* { dg-options "-O -fno-tree-fre -w -Wno-psabi" } */
/* { dg-require-effective-target gcc_frontend } */

typedef unsigned v2ti __attribute__ ((vector_size (32)));

v2ti
foo (v2ti u, v2ti v)
{
  u[0] >>= 0xf;
  v ^= ~v;
  v &= ~u;
  v -= -u;
  return v;
}
