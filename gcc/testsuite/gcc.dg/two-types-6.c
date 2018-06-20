/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */

struct s {
  struct f {}
  struct g {} x; /* { dg-error "expected ';', identifier or " } */
};
