/* Test the legacy option -Werror-implicit-function-declaration */
/* { dg-do compile } */
/* { dg-options "-std=c89 -Werror-implicit-function-declaration" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
void f(void) 
{ 
  puts("Hello"); /* { dg-error "implicit declaration of function" } */
}
