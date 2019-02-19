/* { dg-do compile }  */
/* { dg-additional-options "-Wno-builtin-requires-header" } */

int _setjmp (void *);
void foo (int);

void
bar (int e, int b, char c, void *d)
{
  while (b)
    {
      if (_setjmp (d))
	foo (e);
      if (c)
	{
	  e--;
	  foo (0);
	}
      e++;
    }
}
