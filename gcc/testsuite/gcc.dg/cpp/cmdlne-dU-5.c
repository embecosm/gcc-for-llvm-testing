/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-final { scan-file cmdlne-dU-5.i "^\n*#undef A\n*$" } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
#ifdef A
#ifdef B
#endif
#endif
