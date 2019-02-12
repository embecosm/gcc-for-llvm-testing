/* PR tree-optimization/84503 */
/* { dg-do run } */
/* { dg-options "-O3 -fno-tree-vectorize -fno-ivopts" } */
/* { dg-require-effective-target gcc_frontend } */

#include "pr84503-1.c"
