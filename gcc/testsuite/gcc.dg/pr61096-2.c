/* PR c/61077 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct s { char c[1]; };
extern struct s foo (void);
void
bar (void)
{
  char *t = (foo ()).c; /* { dg-error "13:invalid use of non-lvalue array" } */
}
