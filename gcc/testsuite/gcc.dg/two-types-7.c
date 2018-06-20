/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */

struct s {
  struct f {}
  enum a { X } /* { dg-error "expected ';', identifier or " } */
  struct g {} /* { dg-error "expected identifier " } */
}; /* { dg-warning "no semicolon" } */
