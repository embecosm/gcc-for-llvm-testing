/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized-raw" } */
/* { dg-require-effective-target gcc_frontend } */

int f(int in) {
  in = in | 3;
  in = in ^ 1;
  in = (in & ~(unsigned long)1);
  return in;
}

/* { dg-final { scan-tree-dump-not "bit_and_expr" "optimized" } } */
