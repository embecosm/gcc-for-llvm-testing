/* PR tree-opt/35737 */
/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target builtin_setjmp_longjmp } */

long buf[10];

int foo()
{
  __complex__ int i = 0;

  if (__builtin_setjmp(buf))
  {
    i = 1;
    bar();
  }

  return i == 0;
}

