/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

#include <stdarg.h>

va_list v;
volatile int i;

void foo()
{
  i = va_arg(v, char); /* { dg-warning "is promoted to|so you should|abort" "char" } */
  i = va_arg(v, short); /* { dg-warning "is promoted to|abort" "short" } */
  i = va_arg(v, float); /* { dg-warning "is promoted to|abort" "float" } */
}
