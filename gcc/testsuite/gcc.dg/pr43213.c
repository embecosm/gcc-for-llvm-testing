/* { dg-do compile } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

struct S {
  int i;
};

struct S f(int i)
{
  return *(struct S *)&i;
}

/* { dg-final { scan-assembler-not "memmove" } } */
