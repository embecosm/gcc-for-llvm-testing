/* PR tree-optimization/35899 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89 -O2" } */

int
foo (void)
{
  int a = bar ();
  return a;
}

void
bar (void)		/* { dg-warning "conflicting types for" } */
{
}

/* { dg-message "note: previous implicit declaration" "" { target *-*-* } 8 } */
