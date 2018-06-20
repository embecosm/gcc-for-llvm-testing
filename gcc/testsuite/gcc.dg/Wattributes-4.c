/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int __attribute__((optimize("no-lto"))) main(void){return 0;} /* { dg-warning "bad option" } */
