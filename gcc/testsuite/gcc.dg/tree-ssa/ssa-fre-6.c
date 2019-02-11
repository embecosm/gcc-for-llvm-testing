/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target gcc_frontend } */

 int i; int foo(void) { i = 2; int j = i * 2; int k = i + 2; return j == k; }
/* { dg-final { scan-tree-dump-times "Replaced " 6 "fre1" } } */
