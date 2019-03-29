/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-6.i "^\n*#undef A\n+#define A *\n*$" } } */
#ifdef A
#endif
#define A
#ifdef A
#endif
