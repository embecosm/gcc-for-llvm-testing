/* PR c/53532 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

struct S {};
extern int foo (struct S);

int
main ()
{
  foo ((struct T) {});	/* { dg-error "invalid use of undefined type" } */
  return 0;
}
