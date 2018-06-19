/* PR middle-end/59011 */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target nested_func } */

void
foo (int m)
{
  int a[m];
  void
  bar (void)
  {
    {
      int
      baz (void)
      {
	return a[0];
      }
    }
    a[0] = 42;
  }
  bar ();
}
