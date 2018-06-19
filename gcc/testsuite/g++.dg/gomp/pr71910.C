// PR target/71910
// { dg-do compile }
// { dg-additional-options "-O2" }
// { dg-require-effective-target builtin_exit }

#include <vector>

int
main ()
{
  std::vector<double> vec(10);
#pragma omp parallel
  __builtin_exit (0);
}
