/* { dg-options "-O -fdump-tree-optimized-raw" } */
/* { dg-require-effective-target gcc_internals } */

int f(int a, int b){
  a %= b;
  return a % b;
}
int g(unsigned a, unsigned b){
  a %= b;
  return a < b;
}

/* { dg-final { scan-tree-dump-times "trunc_mod_expr" 1 "optimized" } } */
