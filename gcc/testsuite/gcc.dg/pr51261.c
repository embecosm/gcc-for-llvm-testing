/* PR target/51261 */
/* { dg-do compile } */
/* { dg-options "-fcompare-debug" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (void *p, int n)
{
  __builtin_memset (p, 0xff, n);
}
