/* { dg-do compile } */
/* { dg-options "-fno-tree-ch -fno-tree-fre" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (int *__restrict__ * r, int n)
{
  int *p;
  for (p = *r; p < *r + n; p++)
    ;
}
