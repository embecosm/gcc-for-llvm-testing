/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

/* PR c/43248 */

__extension__ int foo(__SIZE_TYPE__ i)
{
  i ? : (void *){}; /* { dg-error "" } */
}

