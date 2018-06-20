/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wconversion" } */

unsigned f(unsigned a) { return a + -1; }  /* { dg-warning "conversion" } */

