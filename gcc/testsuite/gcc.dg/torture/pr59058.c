/* { dg-do run } */

/* This test iterates until 'b' wraps, however wrapping of signed
   integers is undefined behavior. Based on this, and when compiled with -flto
   it can be inferred that 'b' can never be set to 0, so the branch to 'l1' is
   always taken.  */
/* { dg-require-effective-target gcc_internals } */

extern void abort (void);

short b = 0;

int
main ()
{
  int c = 0;
l1:
  b++;
  c |= b;
  if (b)
    goto l1;
  if (c != -1)
    abort ();
  return 0;
}
