/* { dg-do compile } */
/* { dg-require-effective-target pthread } */
/* { dg-options "-fsave-optimization-record -ftree-loop-vectorize -ftree-parallelize-loops=2" } */
/* { dg-require-effective-target gcc_frontend } */

void
n2 (int ih)
{
  while (ih < 1)
    ++ih;
}
