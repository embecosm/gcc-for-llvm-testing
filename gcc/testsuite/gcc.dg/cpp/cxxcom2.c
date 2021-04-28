/* { dg-do preprocess } */
/* { dg-options "-pedantic -std=c89 -Wall" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#include "cxxcom2.h"

/* { dg-final { scan-file-not cxxcom2.i "is not in C89" } } */

