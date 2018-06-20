/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fdiagnostics-show-caret -Wall" } */

void test_range_of_unused_variable (void)
{
  int redundant; /* { dg-warning "unused variable" } */
/* { dg-begin-multiline-output "" }
   int redundant;
       ^~~~~~~~~
   { dg-end-multiline-output "" } */
}
