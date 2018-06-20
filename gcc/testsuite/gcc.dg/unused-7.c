/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wunused" } */

static int a = 10; /* { dg-warning "defined but not used" } */

