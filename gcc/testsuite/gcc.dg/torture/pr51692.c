/* { dg-do compile } */
/* { dg-require-effective-target builtin_calloc } */
/* { dg-require-effective-target builtin_free } */

int
main ()
{
  volatile double d = 0.0;
  double *p = __builtin_calloc (1, sizeof (double));
  d += 1.0;
  *p += 2.0;
  __builtin_free (p);
  return 0;
}

