/* Test diagnostics for switch statements and labels therein.  Test
   for case ranges with -pedantic-errors.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-pedantic-errors" } */

void
f (int a)
{
  switch (a)
    {
    case 0 ... 0: ; /* { dg-error "range expressions in switch statements are non-standard" } */
    }
}
