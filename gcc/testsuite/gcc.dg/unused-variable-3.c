/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wunused-variable" } */

static const int cmain = 42;	/* { dg-warning "defined but not used" } */

/* Don't warn for unused static consts in headers,
   unless -Wunused-const-variable=2.  */
#line 1 "header.h"
static const int cheader = 42;
