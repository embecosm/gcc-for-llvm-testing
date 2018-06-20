/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99" } */

int foo(int i);

void bar()
{
  __complex__ int i;
  X j;			/* { dg-error "unknown" } */
  if (i = foo(j))
    ;
}
