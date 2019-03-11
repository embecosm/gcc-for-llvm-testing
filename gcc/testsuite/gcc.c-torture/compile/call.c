/* { dg-skip-if "requires untyped assembly" { ! untyped_assembly } { "-O0" } { "" } } */
/* { dg-require-effective-target gcc_frontend } */

int foo () {}

main (a, b)
{
  foo (foo (a, b), foo (b, a));
  return 0;
}
