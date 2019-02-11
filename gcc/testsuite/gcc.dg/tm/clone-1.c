/* { dg-do compile } */
/* { dg-options "-fgnu-tm -fdump-tree-tmmark" } */
/* { dg-require-effective-target gcc_frontend } */

int foo;

__attribute__((transaction_callable))
void cloneme()
{
  foo = 666;
}

/* { dg-final { scan-tree-dump-times "ITM_WU.*foo" 1 "tmmark" } } */
