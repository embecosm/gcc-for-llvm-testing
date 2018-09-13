/* PR target/46088 */
/* { dg-do compile } */
/* { dg-options "-Os -fnon-call-exceptions -fpeel-loops" } */
/* { dg-require-effective-target fpeel_loops } */

extern void bar (void);

void
foo (int i)
{
  if (i >> 3)
    bar ();
}
