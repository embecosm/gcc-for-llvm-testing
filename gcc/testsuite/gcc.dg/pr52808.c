/* { dg-do compile } */
/* { dg-options "-O -ftracer" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

int **fn1 () __attribute__ ((__const__));
int main ()
{
  int i;
  i = 0;
  for (;; i++)
    if (*fn1 ()[i] && !'a' <= 0 && i <= 'z' || *fn1 ()[0] && 'a' <= 'z')
      return 0;
}
