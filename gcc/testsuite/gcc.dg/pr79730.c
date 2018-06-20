/* PR c/79730 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu11" } */

register int x() asm (""); /* { dg-error "invalid storage class" } */
register float y() asm (""); /* { dg-error "invalid storage class" } */
