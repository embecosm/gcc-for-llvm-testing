/* PR debug/46255 */
/* { dg-do compile } */
/* { dg-require-profiling "-fprofile-generate" } */
/* { dg-options "-fcompare-debug -fprofile-generate -O" } */
/* { dg-require-effective-target gcc_internals } */

int bar (void);

void
foo (int i)
{
  while (i)
    i = bar ();
}
