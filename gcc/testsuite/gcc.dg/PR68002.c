/* Ensure static functions can be kept.  */
/* { dg-do compile } */
/* { dg-options "-O1 -fkeep-static-functions" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
/* { dg-require-effective-target gcc_frontend } */

static void bar () { }

/* { dg-final { scan-assembler "bar" } } */
