/* { dg-do compile } */
/* { dg-options "-O2 -g -ftracer -fsched2-use-superblocks" } */
/* { dg-require-effective-target scheduling } */
/* { dg-require-effective-target gcc_internals } */

static int i;
extern void baz(int);
void foo() { i = 3; }
void bar() { baz(i ? 2 : 1); }
