/* { dg-options "-O2 -fsched2-use-superblocks" } */
/* { dg-require-effective-target scheduling } */

int as;

void
ji (int *x4)
{
  if (0)
    {
      unsigned int pv;

      while (as < 0)
        {
          for (*x4 = 0; *x4 < 1; ++(*x4))
yj:
            x4 = (int *)&pv;
          ++as;
        }
    }
  goto yj;
}
