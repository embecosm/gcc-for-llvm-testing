/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-fab1" } */
/* { dg-require-effective-target gcc_frontend } */

#include "builtin-unreachable-6.c"

/* { dg-final { scan-tree-dump-times "lab:" 1 "fab1" } } */
/* { dg-final { scan-tree-dump-not "__builtin_unreachable" "fab1" } } */
