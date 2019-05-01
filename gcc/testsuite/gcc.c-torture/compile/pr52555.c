/* { dg-options "-ffast-math" } */
/* { dg-require-effective-target attr_optimize } */

float farg;
unsigned val;

void __attribute__((optimize("O")))
test()
{
  val = __builtin_ceilf(farg);
}
