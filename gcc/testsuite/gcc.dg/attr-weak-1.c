/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

__inline void foo(void) __attribute__((weak));  /* { dg-warning "inline.*weak" } */

