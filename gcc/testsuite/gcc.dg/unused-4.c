/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wunused -O3" } */

static const int i = 0;		/* { dg-warning "defined but not used" } */
static void f() { }		/* { dg-warning "defined but not used" } */
static inline void g() { }
