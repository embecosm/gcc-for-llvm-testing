/* { dg-do compile } */
/* { dg-options "-O -fno-tree-ccp -fdump-tree-fre1" } */
/* { dg-require-effective-target gcc_internals } */

typedef int v4si __attribute__ ((vector_size (16)));

int
main (int argc, char** argv)
{
  int i = 2;
  int j = ((v4si){0, 1, 2, 3})[i];
  return ((v4si){1, 2, 42, 0})[j];
}

/* { dg-final { scan-tree-dump "return 42;" "fre1" } } */
