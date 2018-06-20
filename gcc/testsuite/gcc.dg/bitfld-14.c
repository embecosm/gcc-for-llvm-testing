/* Test for non-integer bit-field widths.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

enum e { E, F };
struct s {
  int a : (void *)4; /* { dg-error "bit-field 'a' width not an integer constant" } */
  int b : (enum e)F;
  int c : (_Bool)1;
};
