/* PR 17635 */
/* Contributed by Devang Patel  <dpatel@apple.com>  */
/* { dg-do compile } */
/* { dg-options "-O2 -ftree-vectorize" } */
/* { dg-require-effective-target gcc_internals } */

void foo(int i)
{
  while (1)
    if (i) ++i;
}

