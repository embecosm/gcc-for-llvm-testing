/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-3.i "^\n*#define A B\n*$" } } */
#define A B
#ifndef A
#endif
