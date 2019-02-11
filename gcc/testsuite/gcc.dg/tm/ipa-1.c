/* { dg-do compile } */
/* { dg-options "-fgnu-tm -fdump-tree-tmmark-asmname" } */
/* { dg-require-effective-target gcc_frontend } */

void foo(void) __attribute__((transaction_safe));

void bar(void)
{
  __transaction_atomic {
    foo();
  }
}

/* { dg-final { scan-tree-dump-times "_ZGTt3foo" 1 "tmmark" } } */
