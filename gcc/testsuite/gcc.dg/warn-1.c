/* The compiler used to say passing arg 0 of, which is wrong.  */
/* Radar 3069179 */

/* { dg-options "-O3" } */
/* { dg-additional-options "-Wno-int-conversion" } */

static void foo (p)
     int p;
{
}

void bar (void)
{
  void *vp;

  foo (vp);	/* { dg-bogus "passing argument 1 of" } */
}
