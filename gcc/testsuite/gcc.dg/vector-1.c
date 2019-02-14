/* { dg-do compile } */
/* { dg-options "-std=gnu90" } */
/* { dg-additional-options "-Wno-unused-value" } */

typedef int V __attribute__ ((vector_size(4)));
void fn1 ()
{
  (V){(1,0)}[0] = 0;
}
