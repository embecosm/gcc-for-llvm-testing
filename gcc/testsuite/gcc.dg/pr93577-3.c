/* Test ICE with variable-size struct initializer: bug 93577.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target vla_in_struct } */

void
f (int c)
{
  struct s
  {
    int a;
    int x[c];
    struct
    {
      int a, b;
    } nest;
  } v = { .a = 2, .nest.b = 1 }; /* { dg-error "variable-sized object may not be initialized" } */
}
