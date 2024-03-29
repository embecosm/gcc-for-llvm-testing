/* PR c/12446 */
/* Origin: Keith Thompson <kst@cts.com> */

/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */


struct s { char c[1]; };

extern struct s foo(void);

void bar(void)
{
  char *ptr = foo().c; /* { dg-bogus "warning" "warning in place of error" } */
  /* { dg-error "non-lvalue" "array not decaying to lvalue" { target *-*-* } .-1 } */
}
