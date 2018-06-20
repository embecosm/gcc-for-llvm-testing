/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
#include <stdarg.h>
extern void baz(...);	/* { dg-error "requires a named argument" } */
