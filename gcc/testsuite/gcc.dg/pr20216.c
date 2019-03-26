/* { dg-do compile } */
/* { dg-options "-O1" } */
/* { dg-additional-options "-Wno-tautological-constant-out-of-range-compare" } */

static unsigned int *buffer;

void FUNC (void)
{
 unsigned int *base;
 int i, j;

 for (i = 0; i < 4; i++)
  for (j = 0; j < 1600000; j++)
   *base++ = buffer[j];
}
