/* PR c/54363 */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */
/* { dg-additional-options "-Wno-incompatible-pointer-types" } */

struct S { char **a; };

void
test (void)
{
  struct S b = { .a = (char **) { "a", "b" } }; /* { dg-warning "(initialization|excess elements)" } */
  struct S c = { .a = (char *[]) { "a", "b" } };
}
