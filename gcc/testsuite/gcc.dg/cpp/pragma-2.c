/* Verify that preprocessor does not insert redundant newlines
   after #pragma, also check this for #include, #define and #undef */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-dD" } */
#include <stdio.h>

#undef unknow_def

int main () {

#pragma unknown
  {}
  error;
  /* { dg-error "undeclared" "undeclared-variable message" { target *-*-* } .-1 } */
  /* { dg-message "function it appears in" "reminder message" { target *-*-* } .-2 } */ 
}
