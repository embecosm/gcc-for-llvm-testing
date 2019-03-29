/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-13.i "^\n*#undef A\n*$" } } */
#ifdef A
#endif
#ifdef A
#endif
