/* Test diagnostic for GNU extension: statement expressions.  Test
   with -pedantic-errors.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99 -pedantic-errors" } */

int
f (void)
{
  return ({ 1; }); /* { dg-error "ISO C forbids braced-groups within expressions" } */
}
