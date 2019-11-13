/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-options "-nostdinc -P -dU -std=c89" { target *-*-solaris2.* } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-16.i "^\n*#define __STDC__ 1\n*$" } } */
/* { dg-require-effective-target gcc_frontend } */
#ifdef __STDC__
#endif
