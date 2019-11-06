/* Test C11 alignment support.  Test code valid after the resolution
   of DR#444: alignment specifiers for compound literals in _Alignof.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu11" } */
/* { dg-require-effective-target gcc_frontend } */

#include <stddef.h>

size_t align = _Alignof (_Alignas (_Alignof (max_align_t)) char) { 1 };
