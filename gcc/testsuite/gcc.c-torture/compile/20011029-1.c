/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target builtin_setjmp_longjmp } */

void foo (void *) __attribute__ ((noreturn));

void
bar (void *x)
{
  if (__builtin_setjmp (x))
    return;
  foo (x);
}
