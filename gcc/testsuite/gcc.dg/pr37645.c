/* PR c/37645 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

typedef int T __attribute__((__weakref__ ("U")));	/* { dg-warning "attribute ignored" } */
void foo (int i __attribute__((__weakref__ ("j"))));	/* { dg-warning "attribute ignored" } */
