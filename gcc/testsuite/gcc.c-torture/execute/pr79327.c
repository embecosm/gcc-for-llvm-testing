/* PR tree-optimization/79327 */
/* { dg-require-effective-target c99_runtime } */
/* { dg-require-effective-target builtin_sprintf } */

volatile int a;

int
main (void)
{
  int i;
  char buf[64];
  if (__builtin_sprintf (buf, "%#hho", a) != 1)
    __builtin_abort ();
  if (__builtin_sprintf (buf, "%#hhx", a) != 1)
    __builtin_abort ();
  a = 1;
  if (__builtin_sprintf (buf, "%#hho", a) != 2)
    __builtin_abort ();
  if (__builtin_sprintf (buf, "%#hhx", a) != 3)
    __builtin_abort ();
  a = 127;
  if (__builtin_sprintf (buf, "%#hho", a) != 4)
    __builtin_abort ();
  if (__builtin_sprintf (buf, "%#hhx", a) != 4)
    __builtin_abort ();
  return 0;
}
