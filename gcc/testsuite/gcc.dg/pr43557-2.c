/* PR debug/43557 */
/* { dg-do compile } */
/* { dg-additional-options "-Wno-unused-value" } */

extern struct S g;

void
f2 (void)
{
  &g;
}
