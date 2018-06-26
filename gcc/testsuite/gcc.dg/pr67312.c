/* { dg-do compile } */
/* { dg-options "-O0 -ftree-coalesce-vars" } */
/* { dg-require-effective-target gcc_internals } */

void foo (int x, int y)
{
    y = x;
}
