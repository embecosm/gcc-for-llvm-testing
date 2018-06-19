/* { dg-do compile } */
/* { dg-options "-g -O" } */
/* { dg-require-effective-target vla_in_struct } */

extern void foo (void);

static
void baz (int i)
{
  foo ();
  typedef char A[i];
  struct { A b; } *x = 0;
}

void
bar (int i)
{
  baz (i);
}
