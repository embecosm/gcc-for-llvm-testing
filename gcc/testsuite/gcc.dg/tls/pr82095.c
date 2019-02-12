/* PR middle-end/82095 */
/* { dg-do compile } */
/* { dg-options "-Og -fno-tree-ccp" } */
/* { dg-require-effective-target tls } */
/* { dg-add-options tls } */
/* { dg-require-effective-target gcc_frontend } */

static int b;
static __thread int c;

void
foo (void)
{
  if (b)
    if (c)
      b = 1;
}
