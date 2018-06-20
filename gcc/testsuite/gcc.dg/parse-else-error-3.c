/* PR 23722 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fsyntax-only" } */
int f()
{

  else  /* { dg-error "'else' without a previous 'if'" } */
    {
      return 0;
    }
}
