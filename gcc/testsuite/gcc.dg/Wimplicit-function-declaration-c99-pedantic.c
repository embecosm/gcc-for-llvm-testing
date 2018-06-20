/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c99 -pedantic-errors -Wall" } */

void f(void) 
{ 
  puts("Hello"); /* { dg-error "implicit declaration of function" } */
}
