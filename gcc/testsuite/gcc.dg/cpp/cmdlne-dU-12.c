/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-12.i "^\n*#define A 1\n*$" } } */
/* { dg-require-effective-target gcc_frontend } */
#define A 1
#if A
#endif
