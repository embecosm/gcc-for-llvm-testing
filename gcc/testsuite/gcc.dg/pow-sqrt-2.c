/* { dg-do run } */
/* { dg-options "-O2 -ffast-math --param max-pow-sqrt-depth=5" } */
/* { dg-require-effective-target double64plus } */
/* { dg-additional-options "-Wno-absolute-value" } */

#define EXPN (-5.875)
#include "pow-sqrt.x"
