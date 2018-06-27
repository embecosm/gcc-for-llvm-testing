/* PR debug/43084 */
/* { dg-do compile } */
/* { dg-options "-O1 -fwhole-program -fcompare-debug" } */
/* { dg-require-effective-target gcc_internals } */

struct S
{
  int a;
};

int
main ()
{
  struct S s;
  struct S *p = &s;
  return p->a;
}
