/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-final { scan-file cmdlne-dU-18.i "^\n*x 1 y\n+#define A 1\n*$" } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-require-effective-target gcc_frontend } */
#define A 1
x A y
