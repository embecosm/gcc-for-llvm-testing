/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized-raw" } */
/* { dg-require-effective-target gcc_frontend } */

int f(unsigned a,unsigned b){
    a *= 3;
    b *= 3;
    return a == b;
}

/* { dg-final { scan-tree-dump-not "mult_expr" "optimized" } } */
