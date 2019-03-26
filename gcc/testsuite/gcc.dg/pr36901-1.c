/* { dg-do compile } */
/* { dg-options "-pedantic-errors" } */
/* { dg-require-effective-target gcc_frontend } */
#include "pr36901-system.h"
void foo(void)
{
  int s = sc;
}
