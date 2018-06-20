/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

#include <stdint.h>

void f1();
void f2();

void
foo (int *a)
{
  if ((intptr_t) a == 0)
    {
      f1 ();
      if (a)
	f2 (); 
    }
}

/* { dg-final { scan-tree-dump "if \\(a == 0B\\)" "gimple" } } */
