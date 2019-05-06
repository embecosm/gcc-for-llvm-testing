/* { dg-do compile } */
/* { dg-options "-std=c89 -Wimplicit-function-declaration" } */
/* { dg-require-effective-target gcc_frontend } */

void f(void) 
{ 
  puts("Hello"); /* { dg-warning "implicit declaration of function" } */
}
