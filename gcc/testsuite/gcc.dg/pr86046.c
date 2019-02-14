/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-unused-value" } */

typedef int V __attribute__ ((vector_size(4)));
void fn1 ()
{
  (V){(1,0)}[1] = 0;  // out-of-bound access
}
