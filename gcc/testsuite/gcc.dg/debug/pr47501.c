/* { dg-do compile } */
/* { dg-options "-Os -fmodulo-sched -fcompare-debug" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (void)
{
  unsigned numlen;
  unsigned foldlen;
  for (; foldlen; foldlen -= numlen)
    foo ();
}
