/* { dg-do run } */
/* { dg-options "-O2 -funsafe-math-optimizations -fno-finite-math-only -DUNSAFE" } */
/* { dg-add-options ieee } */
/* { dg-require-effective-target builtin_isnan } */
/* { dg-require-effective-target builtin_isinf } */
/* { dg-require-effective-target builtin_finite } */

#include "tg-tests.h"

int main(void)
{
  return main_tests ();
}
