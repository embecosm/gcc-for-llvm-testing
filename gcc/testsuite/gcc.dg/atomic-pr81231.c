/* PR c/81231 */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

enum E;

void
foo (void)
{
  __atomic_load_n ((enum E *) 0, 0); /* { dg-error "incompatible" } */
  __atomic_load_n ((enum X *) 0, 0); /* { dg-error "incompatible" } */
}
