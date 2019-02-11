/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-require-effective-target gcc_frontend } */

void*f(){
    char*p=__builtin_malloc(42);
    __builtin_memset(p,0,42);
    __builtin_memset(p,0,42);
    return p;
};

/* { dg-final { scan-tree-dump-not "malloc" "optimized" } } */
/* { dg-final { scan-tree-dump-times "calloc" 1 "optimized" } } */
/* { dg-final { scan-tree-dump-not "memset" "optimized" } } */
