/* { dg-do compile }  */
/* { dg-options "-O2 -fno-early-inlining -fno-ipa-cp" } */
/* { dg-require-effective-target gcc_internals } */

float baz (void)
{
  return 0;
}

static inline int bar (int (*ibaz) (void))
{
  return ibaz ();
}

void foo (void)
{
  bar((int (*)(void))baz);
}
