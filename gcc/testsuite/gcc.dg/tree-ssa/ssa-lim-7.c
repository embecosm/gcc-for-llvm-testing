/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-lim2-details" } */
/* { dg-require-effective-target gcc_frontend } */

extern const int srcshift;

void foo (int *srcdata, int *dstdata)
{
  int i;

  for (i = 0; i < 256; i++)
    dstdata[i] = srcdata[i] << srcshift;
}

/* { dg-final { scan-tree-dump "Moving statement" "lim2" } } */
