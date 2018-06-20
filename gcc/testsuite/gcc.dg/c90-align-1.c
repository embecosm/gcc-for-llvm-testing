/* Test _Alignof and _Alignas not in C90.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */

int a = _Alignof (int); /* { dg-error "ISO C90 does not support '_Alignof'" } */
_Alignas (int) int b; /* { dg-error "ISO C90 does not support '_Alignas'" } */
