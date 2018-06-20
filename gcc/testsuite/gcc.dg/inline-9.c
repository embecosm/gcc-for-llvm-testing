/* Test inline main, gnu99 mode, hosted, -pedantic-errors.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99 -fhosted -pedantic-errors" } */

inline int main (void); /* { dg-error "cannot inline function 'main'" } */
