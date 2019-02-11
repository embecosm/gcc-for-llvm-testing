/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-ccp2" } */
/* { dg-require-effective-target gcc_frontend } */

struct a {int a,b;};
const static struct a a;
static int b[10];
int c;
int
test()
{
  return a.a+b[c];
}
/* { dg-final { scan-tree-dump "return 0;" "ccp2" } } */
