/* Test for flexible array members: not permitted in unions.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1999 -pedantic-errors" } */

typedef char T[];
union u { int a; T b; }; /* { dg-error "flexible array member in union" } */
