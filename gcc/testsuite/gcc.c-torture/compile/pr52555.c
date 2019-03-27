/* { dg-options "-ffast-math" } */
/* { dg-additional-options "-Wno-unknown-attributes" } */

float farg;
unsigned val;

void __attribute__((optimize("O")))
test()
{
  val = __builtin_ceilf(farg);
}
