/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-8.i "^\n*B D\n+#define A\\(x\\) B x\n+#define C D\n*$" } } */
#define A(x) B x
#define C D
A(C)
