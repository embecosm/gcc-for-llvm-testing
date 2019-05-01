/* { dg-do compile } */
/* { dg-require-effective-target attr_optimize } */

int __attribute__((optimize("no-lto"))) main(void){return 0;} /* { dg-warning "bad option" } */
