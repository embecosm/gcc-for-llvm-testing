/* PR 71619 */

/* { dg-do compile } */
/* { dg-options "-O --param=max-predicted-iterations=0" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */

void
foo ()
{
  int count = -10;
  while (count++);
}
