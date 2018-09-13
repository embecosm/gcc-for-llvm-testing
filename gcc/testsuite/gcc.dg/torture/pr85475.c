/* { dg-do compile } */
/* { dg-additional-options "-fpeel-loops" } */
/* { dg-require-effective-target fpeel_loops } */

int
nj (int le)
{
  int zb;

  for (zb = 0; zb < 16; ++zb)
    le += le;

  return le * le;
}
