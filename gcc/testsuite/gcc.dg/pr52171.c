/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-final { scan-assembler-not "memcmp" } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument"} */
#include <string.h>
struct A { int x; } a, b;

extern char s[], t[];

int foo ()
{
  return memcmp (&a, &b, sizeof (struct A)) == 0;
}
