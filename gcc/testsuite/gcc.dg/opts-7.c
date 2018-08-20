/* PR driver/71063 */
/* Test we don't ICE.  */
/* { dg-do compile } */
/* { dg-options "--help=^" } */
/* { dg-require-effective-target gcc_frontend } */

/* { dg-error "missing argument to" "" { target *-*-* } 0 } */
