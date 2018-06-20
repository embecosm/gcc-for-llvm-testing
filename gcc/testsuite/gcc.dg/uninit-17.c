/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O -Wuninitialized" } */

typedef _Complex float C;
C foo(int cond)
{
  C f;
  __imag__ f = 0;
  if (cond)
    {
      __real__ f = 1;
      return f;
    }
  return f;	/* { dg-warning "may be used" "unconditional" } */
}
