/* { dg-require-effective-target builtin_shuffle } */
/* { dg-require-effective-target noclone } */

typedef unsigned short V __attribute__((vector_size(32)));
typedef V VI;

#include "vshuf-16.inc"
#include "vshuf-main.inc"
