/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int i)
{
  if (i)
    {
      if (i)
	return 1;
      else
	return 0;
    }
  return 0;
}

/* { dg-final { scan-tree-dump "Removing unexecutable edge" "fre1" } } */
