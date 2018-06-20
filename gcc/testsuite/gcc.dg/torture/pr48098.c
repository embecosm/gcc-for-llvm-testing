/* { dg-do compile } */
/* { dg-require-effective-target builtin_malloc } */

void
foo (int n)
{
  static char *__restrict *p;
  int i;
  p = __builtin_malloc (n);
  for (i = 0; i < n; i++)
    p[i] = 0;
}

