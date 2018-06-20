/* PR c/63626 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

/* Test that we don't output the warning twice.  */

inline int foo (void); /* { dg-bogus "inline function.*inline function" } */
/* { dg-warning "inline function .foo. declared but never defined" "" { target *-*-* } .-1 } */
