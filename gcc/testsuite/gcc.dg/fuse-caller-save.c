/* { dg-do run } */
/* { dg-options "-fipa-ra" } */
/* { dg-require-effective-target gcc_internals } */
/* Testing -fipa-ra optimization option.  */

static int __attribute__((noinline))
bar (int x)
{
  return x + 3;
}

int __attribute__((noinline))
foo (int y)
{
  return y + bar (y);
}

int
main (void)
{
  return !(foo (5) == 13);
}
