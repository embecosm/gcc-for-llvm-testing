/* { dg-do run } */
/* { dg-options "-O2 -ffast-math -ftree-vectorize -mavx" } */
/* { dg-require-effective-target avx } */

#define CHECK_H "avx-check.h"
#define TEST avx_test

#include "sse2-lrint-vec.c"
