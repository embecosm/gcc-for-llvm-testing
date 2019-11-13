/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-final { scan-file cmdlne-dU-14.i "^\n*B\n+#define A B\n+B\n*$" } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-require-effective-target gcc_frontend } */
#define A B
A
A
