/* { dg-do run } */
/* { dg-additional-options "-fsanitize=unreachable" } */
/* { dg-require-effective-target builtin_exit } */

char a, c;
short b;

int
main ()
{
  unsigned d = 0;
  int e = 1;
  for (a = 0; a < 2; a++)
    {
      if (e)
        c--;
      for (; d < 2; d++)
        for (b = 0; b; b++)
          ;
      e = 0;
    }
  __builtin_exit (0);
}
