/* Test for no ICE with an undeclared identifier in an enum in old-style
   parameter decls.  PR 12560.  */
/* { dg-options "-w" } */
/* { dg-require-effective-target gcc_frontend } */

foo(c)
     enum { a = b } c;  /* { dg-error "undeclared|for each" } */
{
}
