/* { dg-do preprocess } */
/* { dg-options "-C -P" } */
/* { dg-require-effective-target gcc_frontend } */

#define macro(X) X

macro(
// Comment1
x
// Comment2
);

/* { dg-final { scan-file cmdlne-C3.i "\\\*\\\/ x \\\/\\\*" } } */

