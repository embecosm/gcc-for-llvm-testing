/* Test for rejection of sizeof on bit-fields.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

struct { int a : 1; } x;

int r = sizeof (x.a); /* { dg-error "'sizeof' applied to a bit-field" } */
