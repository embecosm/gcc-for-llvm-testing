/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-ivcanon-details" } */
/* { dg-require-effective-target gcc_frontend } */

void bar();
void foo(unsigned dst)
{
  unsigned end = dst;
  do {
    bar();
    dst += 2;
  } while (dst < end);
}

/* { dg-final { scan-tree-dump " zero if " "ivcanon" } } */
