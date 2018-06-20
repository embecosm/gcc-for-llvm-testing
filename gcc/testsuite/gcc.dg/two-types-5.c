/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */

struct f {}
struct g {} /* { dg-error "expected ';', identifier or " } */
int f(); /* { dg-error "expected ';', identifier or " } */
