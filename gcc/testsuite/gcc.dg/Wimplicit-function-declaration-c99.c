/* { dg-do compile } */
/* { dg-options "-std=c99" } */
/* { dg-require-effective-target gcc_frontend } */

void f(void) 
{ 
  puts("Hello"); /* { dg-warning "implicit declaration of function" } */
}
