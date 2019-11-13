/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-final { scan-file cmdlne-dU-2.i "^\n*#define A *\n*$" } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-require-effective-target gcc_frontend } */
#define A
#ifdef A
#endif
