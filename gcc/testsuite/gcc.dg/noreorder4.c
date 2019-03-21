/* { dg-do compile } */
/* { dg-options "-O2 -fno-toplevel-reorder" } */
/* { dg-require-effective-target gcc_frontend } */
#define NOREORDER
#include "noreorder.c"
/* { dg-final { scan-assembler "bozo.*jukjuk.*func1.*barbar.*func2" } } */
