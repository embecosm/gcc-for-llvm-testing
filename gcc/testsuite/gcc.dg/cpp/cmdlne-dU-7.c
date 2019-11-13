/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-7.i "^\n*B\n+#define A B\n+C\n+#define A C\n*$" } } */
/* { dg-require-effective-target gcc_frontend } */
#define A B
A
#undef A
#define A C
A
