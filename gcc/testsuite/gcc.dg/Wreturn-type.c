/* PR c++/4872 */
/* { dg-do compile } */
/* { dg-options "-Wreturn-type" } */
/* { dg-require-effective-target gcc_frontend } */

static inline int f() {}     /* { dg-warning "return" "missing return" } */
