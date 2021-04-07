/* { dg-do run } */
/* { dg-options "-O2 -ffast-math --param max-pow-sqrt-depth=3" } */
/* { dg-require-effective-target double64plus } */
/* { dg-additional-options "-Wno-absolute-value" } */

#define EXPN (1.25)
#include "pow-sqrt.x"
