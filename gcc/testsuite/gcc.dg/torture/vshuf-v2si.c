/* { dg-do run } */
/* { dg-options "-DEXPENSIVE" { target run_expensive_tests } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "*" } { "-O2" } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "-flto" } { "" } } */
/* { dg-require-effective-target builtin_shuffle } */

#if __SIZEOF_INT__ == 4
typedef unsigned int V __attribute__((vector_size(8)));
typedef V VI;
#elif __SIZEOF_LONG__ == 4
typedef unsigned long V __attribute__((vector_size(8)));
typedef V VI;
#else
#define UNSUPPORTED
#endif

#include "vshuf-2.inc"
#include "vshuf-main.inc"
