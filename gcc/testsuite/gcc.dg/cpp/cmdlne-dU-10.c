/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-final { scan-file cmdlne-dU-10.i "^\n*C\n+#define B C\n+#define A B\n*$" } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-require-effective-target gcc_frontend } */
/* This file deliberately has no final newline.  */
#define A B
#define B C
A
