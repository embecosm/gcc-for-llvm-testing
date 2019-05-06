/* PR c/81779 */
/* { dg-do compile } */
/* { dg-options "-Wdeclaration-after-statement" } */
/* { dg-require-effective-target gcc_frontend } */

#include <stdbool.h>

bool
f2 (char *p)
{
  if (!p)
    return false;

  bool ret = true; /* { dg-warning "ISO C90 forbids mixed declarations and code" } */
  return ret;
}
