/* PR c/37529 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } */

void
foo ()
{
  goto *;	/* { dg-error "expected expression before" } */
}
