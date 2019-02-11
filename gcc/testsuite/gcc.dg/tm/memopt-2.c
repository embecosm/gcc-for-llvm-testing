/* { dg-do compile } */
/* { dg-options "-fgnu-tm -O -fdump-tree-tmmemopt" } */
/* { dg-require-effective-target gcc_frontend } */

char c;

void f(void)
{
  __transaction_atomic {
    ++c;
  }
}

/* { dg-final { scan-tree-dump-times "transforming.*RfWU1 \\(&c" 1 "tmmemopt" } } */
/* { dg-final { scan-tree-dump-times "transforming.*WaWU1 \\(&c" 1 "tmmemopt" } } */
