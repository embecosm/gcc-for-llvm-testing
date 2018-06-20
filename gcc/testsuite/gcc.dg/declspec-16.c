/* Test diagnostic for empty declarations in old-style parameter
   declarations.  Test with -pedantic.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89 -pedantic" } */

void
f (a, b)
     int; /* { dg-warning "empty declaration" } */
     register; /* { dg-warning "empty declaration" } */
{
}
