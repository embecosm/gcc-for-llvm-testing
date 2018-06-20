/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

char *foo() __attribute__((alloc_size(1))); /* { dg-warning "outside range" } */

