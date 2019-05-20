/* { dg-do compile } */
/* { dg-options "-O -Wall" } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  while (1)
    for (;;({ continue; }))
      ;
}
