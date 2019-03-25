/* { dg-do compile } */
/* { dg-options "-fallow-parameterless-variadic-functions" } */
/* { dg-require-effective-target gcc_frontend } */
#include <stdarg.h>
extern void baz(...);
