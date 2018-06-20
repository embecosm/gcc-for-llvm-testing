/* Test that parameter without declaration specifiers in old-style
   parameters is not accepted.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } */

void
f(a)
     a; /* { dg-error "parse error|syntax error|no type or storage class|expected declaration specifiers" } */
{
}
