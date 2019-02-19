/* Verify that pairs of types in <stdint.h> are corresponding types.
   Freestanding version.  */
/* { dg-do compile } */
/* { dg-options "-std=iso9899:1999 -ffreestanding" } */
/* { dg-additional-options "-Wno-pointer-sign" } */

/* The test is that there are no diagnostics, so just include the
   hosted version.  */
#include "c99-stdint-3.c"
