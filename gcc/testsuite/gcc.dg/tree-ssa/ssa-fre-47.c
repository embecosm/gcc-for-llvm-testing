/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int i)
{
  if (i)
    {
      if (i)
	return 0;
      else
	return 1;
    }
  return 0;
}

/* { dg-final { scan-tree-dump "return 0;" "fre1" } } */
