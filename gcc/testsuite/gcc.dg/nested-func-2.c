/* PR middle-end/18820 */
/* Check that we reject nested functions as initializers
   of static variables.  */

/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */
/* { dg-require-effective-target nested_func } */

struct S {
  void (*f)(int);
};

extern void baz(struct S *);
extern void p(int);

void foo(void)
{
  int u;

  void bar(int val)
    {
      u = val;
    }

  static struct S s = { bar }; /* { dg-error "(is not constant)|(near initialization)" } */

  baz(&s);
  p(u);
}
