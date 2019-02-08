/* PR inline-asm/63282 */
/* { dg-require-effective-target asm_goto } */

void bar (void);

void
foo (void)
{
  asm volatile goto ("" : : : : a, b);
a:
  bar ();
b:
  return;
}
