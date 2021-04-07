/* { dg-do run } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-require-effective-target builtin_realloc } */

int j;
int main ()
{
  int i = 1;
  int **p;
  j = 0;
  p = __builtin_malloc (sizeof (int *));
  *p = &i;
  p = __builtin_realloc (p, 2 * sizeof (int *));
  **p = 0;
  if (i != 0)
    __builtin_abort ();
  return j;
}

/* { dg-final { scan-tree-dump "Replaced j with 0" "fre1" } } */
