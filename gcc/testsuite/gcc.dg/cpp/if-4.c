/* Regression test for proper error message.  The token name isn't
   NUL terminated, so we would print garbage after it.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

#if 1 += 2   /* { dg-error "is not valid" "+= in if" } */
syntax_error
#endif
int foo;
