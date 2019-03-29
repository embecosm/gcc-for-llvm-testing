/* PR rtl-optimization/50615 */
/* Testcase by Zdenek Sojka <zsojka@seznam.cz> */

/* { dg-do compile } */
/* { dg-options "-O --param max-cse-insns=1" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */

int
foo (int a)
{
  if (!a)
    return 1;

  {
    int s[a];
    return 0;
  }
}
