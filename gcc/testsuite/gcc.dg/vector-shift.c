/* { dg-do compile } */
/* { dg-options "-fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

typedef unsigned vec __attribute__ ((vector_size (4 * sizeof (int))));

void
f (vec *x)
{
  *x = (*x << 4) << 3;
}

/* { dg-final { scan-tree-dump "<< 7" "original" } } */
