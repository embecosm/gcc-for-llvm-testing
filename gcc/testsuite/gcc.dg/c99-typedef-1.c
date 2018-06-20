/* Test typedef redeclaration not permitted in C99.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1999 -pedantic-errors" } */

typedef int TI; /* { dg-message "previous declaration" } */
typedef int TI; /* { dg-error "redefinition of typedef" } */
