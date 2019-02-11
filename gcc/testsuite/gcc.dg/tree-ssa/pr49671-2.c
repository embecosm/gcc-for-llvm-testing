/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" }  */
/* { dg-require-effective-target gcc_frontend } */
int t;
static inline int cvmx_atomic_get32(int *ptr)
{
    return *(volatile int*)ptr;
}
void f(void)
{
  while (!cvmx_atomic_get32(&t))
    ;
}

/* { dg-final { scan-tree-dump "\{v\}" "optimized" } } */


