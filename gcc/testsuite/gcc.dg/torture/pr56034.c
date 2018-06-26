/* { dg-do compile } */
/* { dg-options "-ftree-loop-distribution" } */
/* { dg-require-effective-target gcc_internals } */

int a, b, *p;

void f(void)
{
  int *q;

  while(b++)
    {
      int i;
      p = &i;
      a = *q;
    }

  if(a)
    for(;; b++);
}
