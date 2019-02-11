/* { dg-do compile } */
/* { dg-options "-fopenmp -fdump-tree-ompexp" } */
/* { dg-require-effective-target gcc_frontend } */

extern void bar(int);

void foo (int n)
{
  int i;

  #pragma omp for schedule(nonmonotonic:dynamic, 2)
  for (i = 0; i < n; ++i)
    bar(i);
}

/* { dg-final { scan-tree-dump-times "GOMP_loop_nonmonotonic_dynamic_start" 1 "ompexp" } } */
/* { dg-final { scan-tree-dump-times "GOMP_loop_nonmonotonic_dynamic_next" 1 "ompexp" } } */
