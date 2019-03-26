/* { dg-do compile } */
/* { dg-options "-pedantic-errors -w" } */
/* { dg-require-effective-target gcc_frontend } */
#include "pr36901.h"
void foo(void)
{
  int s = sc;
}
