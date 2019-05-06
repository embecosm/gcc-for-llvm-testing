/* Origin: PR preprocessor/60723

   { dg-do compile }
   { dg-options -no-integrated-cpp }  */
/* { dg-additional-options "-Wno-unused-value" } */
/* { dg-require-effective-target gcc_frontend } */

#include "syshdr5.h"

int
main()
{
  FOO(1/0 /*  { dg-warning "division by zero" }  */
      );
  return 0;
}
