/* Test _Float128x type-generic built-in functions: __builtin_isinf_sign.  */
/* { dg-do run } */
/* { dg-options "" } */
/* { dg-add-options float128x } */
/* { dg-add-options ieee } */
/* { dg-require-effective-target float128x_runtime } */
/* { dg-require-effective-target builtin_isinf } */

#define WIDTH 128
#define EXT 1
#include "floatn-tg-2.h"
