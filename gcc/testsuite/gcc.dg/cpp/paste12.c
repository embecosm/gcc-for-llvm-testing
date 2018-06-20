/*
  { dg-options "-ftrack-macro-expansion=0" }
  { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
*/

/* Test correct diagnostics when pasting in #include.
   Source: PR preprocessor/6780.  */

#define inc2(a,b) <##a.b>
#define INC(X) inc2(X,h)
#include INC(stdio) /* { dg-error "pasting \"<\" and \"stdio\" does not" } */
