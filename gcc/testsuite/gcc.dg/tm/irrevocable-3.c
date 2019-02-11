/* { dg-do compile } */
/* { dg-options "-fgnu-tm -fdump-tree-tmmark" } */
/* { dg-require-effective-target gcc_frontend } */

extern void bar(void) __attribute__((transaction_callable));

void
foo()
{
	__transaction_relaxed {
		bar();
	}
}

/* { dg-final { scan-tree-dump-times "doesGoIrrevocable" 1 "tmmark" } } */
