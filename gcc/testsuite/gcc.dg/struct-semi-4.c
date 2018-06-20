/* Test for missing semicolons in structures: anonymous structures and
   similar cases.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

struct s { struct { int a; } }; /* { dg-warning "no semicolon" } */
int *f (struct s *p) { return &p->a; }
