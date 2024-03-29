/* { dg-do compile } */
/* { dg-options "-fopenmp -fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_frontend } */

void f1(void)
{
  #pragma omp barrier
}

void f2(_Bool p)
{
  if (p)
    {
      #pragma omp barrier
    }
}

/* { dg-final { scan-tree-dump-times "GOMP_barrier" 2 "gimple" } } */
