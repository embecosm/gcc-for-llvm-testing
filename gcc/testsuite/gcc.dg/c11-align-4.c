/* Test C11 alignment support.  Test reducing alignment (assumes there
   are at least some alignment constraints).  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c11 -pedantic-errors" } */
/* { dg-skip-if "no alignment constraints" { no_alignment_constraints } } */

#include <stddef.h>

_Alignas (_Alignof (char)) max_align_t x; /* { dg-error "reduce alignment" } */
