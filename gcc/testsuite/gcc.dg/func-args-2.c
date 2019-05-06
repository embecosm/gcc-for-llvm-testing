/* PR c/27420 */
/* { dg-do compile } */
/* { dg-options "-w" } */
/* { dg-require-effective-target gcc_frontend } */

void foo();
void foo(struct A a) {}  /* { dg-error "incomplete type" } */
