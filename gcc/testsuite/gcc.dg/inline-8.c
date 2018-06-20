/* Test inline main, gnu99 mode, hosted.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99 -fhosted" } */

inline int main (void); /* { dg-warning "cannot inline function 'main'" } */
