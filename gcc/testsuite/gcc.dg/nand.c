/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

unsigned f(unsigned x, unsigned y){
  return (x | y) & ~x;
}
unsigned g(unsigned x, unsigned y){
  return ~x & (y | x);
}

/* { dg-final { scan-tree-dump-times "return ~x & y;" 2 "original" } } */
