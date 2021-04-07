/* { dg-options "-O0" } */
/* { dg-do compile } */
/* { dg-additional-options "-Wno-unknown-attributes" } */

extern unsigned foo (void);
extern void bar (void);

__attribute__ ((optimize ("O2")))
void bak ()
{
  unsigned a;
  while (1)
    {
      a = foo ();
      while (a)
	{
	  a &= 1;
	  bar ();
	}
    }
}
