/* Test ICE with variable-size struct initializer: bug 93577.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target vla_in_struct } */

void
f (int c)
{
  struct s
  {
    int x[c];
    struct
    {
      int a, b;
    } nest;
  } v = { .nest.b = 1, .nest.a = 2 }; /* { dg-error "variable-sized object may not be initialized" } */
}
