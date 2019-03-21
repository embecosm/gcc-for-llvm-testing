/* { dg-options "-fira-algorithm=priority" } */
/* { dg-require-effective-target gcc_frontend } */
char **
foo (char **p, char *cmp, unsigned i)
{
  for (; *p; p++)
    if (__builtin_strncmp (*p, cmp, i))
      if (i == __builtin_strlen (*p))
	break;
  return p;
}
