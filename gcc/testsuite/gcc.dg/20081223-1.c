/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-options "-flto -ffat-lto-objects" { target lto } }  */

typedef struct foo_ foo_t;
foo_t bar;  /* { dg-error "storage size of 'bar' isn't known" }  */
