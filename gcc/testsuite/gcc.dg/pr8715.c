/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wsign-compare -std=c99" } */

#include <stdbool.h>

int foo()
{
  unsigned char b = '1';

  bool x = ~b; /* { dg-warning "promoted ~unsigned is always non-zero" } */

  return 0;
}
