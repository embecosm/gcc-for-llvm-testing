/* { dg-do compile } */
/* { dg-options "-O -fpeel-loops" } */
/* { dg-require-effective-target fpeel_loops } */

extern char outbuffer[];
extern char buffer[];

void foo(int j)
{
  unsigned i, fp = fp;
  for (i = 0; i < 6; i++)
    buffer[j++] = outbuffer[fp - i];
}
