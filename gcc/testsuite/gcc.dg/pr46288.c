/* { dg-do compile } */
/* { dg-options "-O -fno-tree-dce" } */
/* { dg-require-effective-target gcc_internals } */

void foo (int i)
{
  __builtin_expect (i, i);
}

