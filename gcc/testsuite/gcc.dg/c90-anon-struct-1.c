/* Test for anonymous structures and unions not permitted in C90.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */

struct s
{
  int a;
  struct
  {
    int b;
  }; /* { dg-error "unnamed structs" } */
};
