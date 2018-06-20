/* PR 55383 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wcast-qual" } */

void set(void*);

int foo(int argc)
{
  volatile double val;
  set((void*)&val); /* { dg-warning "cast discards .volatile. qualifier" } */
}
