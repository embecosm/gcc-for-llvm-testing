/* PR rtl-optimization/56117 */
/* { dg-do compile } */
/* { dg-options "-O2 -fsched2-use-superblocks" } */
/* { dg-require-effective-target scheduling } */

void
foo (void *p)
{
  __builtin_prefetch (p);
}
