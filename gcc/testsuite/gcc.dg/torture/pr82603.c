/* { dg-do compile } */
/* { dg-additional-options "-ftree-loop-vectorize" } */
/* { dg-require-effective-target gcc_frontend } */

int
mr (unsigned int lf, int ms)
{
  unsigned int sw = 0;
  char *cu = (char *)&ms;

  while (ms < 1)
    {
      if (lf == 0)
	ms = 0;
      else
	ms = 0;
      ms += ((lf > 0) && ((lf > sw) ? 1 : ++*cu));
    }

  if (lf != 0)
    cu = (char *)&sw;
  *cu = lf;

  return ms;
}
