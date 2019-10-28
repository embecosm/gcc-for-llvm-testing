/* { dg-do compile } */
/* { dg-options "-O -fexceptions -fnon-call-exceptions -ftrapv" } */
/* { dg-require-effective-target exceptions } */
/* { dg-skip-if "" { ! fexceptions } } */

void
foo ()
{
  int n = 0;
  while (1)
    {
      int i[n % 1];
      n++;
    }
}

