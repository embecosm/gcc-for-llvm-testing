/* { dg-do run { target *-*-linux* *-*-gnu* } } */
/* { dg-options "-O2 -fdump-tree-strlen" } */
/* { dg-require-effective-target gcc_frontend } */

#define USE_GNU
#include "strlenopt-31.c"

/* { dg-final { scan-tree-dump-times "stpcpy \\(" 1 "strlen" } } */
/* { dg-final { scan-tree-dump-times "memcpy \\(" 2 "strlen" } } */
/* { dg-final { scan-tree-dump-not "strlen \\(" "strlen" } } */
