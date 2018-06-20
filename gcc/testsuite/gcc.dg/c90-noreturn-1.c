/* Test _Noreturn not in C90.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */

_Noreturn void f (void); /* { dg-error "ISO C90 does not support '_Noreturn'" } */
