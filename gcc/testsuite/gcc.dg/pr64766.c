/* PR c/64766 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
foo ()
{
}

void foo () = 0; /* { dg-error "is initialized like a variable|invalid initializer" } */
