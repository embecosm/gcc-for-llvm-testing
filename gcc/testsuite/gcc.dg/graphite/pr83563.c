/* { dg-do compile } */
/* { dg-options "-O -fgraphite -ftree-loop-distribution -fno-tree-dominator-opts -fno-tree-sink -fno-tree-dce" } */
/* { dg-require-effective-target gcc_frontend } */

void
sy (void)
{
  int hb;

  for (hb = 1; hb != 0; hb += hb)
    {
    }

  while (hb < 1)
    ++hb;
}
