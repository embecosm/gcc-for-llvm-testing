/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-forwprop1" }  */
/* { dg-require-effective-target gcc_frontend } */

/* We may not optimize this to b->t[i] = 1.  */

struct a
{
  int t[10];
};

void f(struct a * b, __SIZE_TYPE__ i)
{
  int *c = b->t;
  c[i] = 1;
}

/* { dg-final { scan-tree-dump-times "\\\[\[^\n\r\]*\\\] = 1;" 0 "forwprop1" } } */
