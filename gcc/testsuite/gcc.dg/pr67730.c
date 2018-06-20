/* PR c/67730 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

#include <stddef.h>

void
fn1 (void)
{
  return NULL; /* { dg-warning "10:.return. with a value" } */
}
