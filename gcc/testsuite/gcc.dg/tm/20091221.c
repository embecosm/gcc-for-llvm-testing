/* { dg-do compile } */
/* { dg-options "-fgnu-tm -fdump-tree-tmedge" } */
/* { dg-require-effective-target gcc_frontend } */

int i;
extern void virgin () __attribute__((transaction_pure));

void
foo()
{
	__transaction_atomic {
	    virgin(i);
	}
}

/* { dg-final { scan-tree-dump-times "readOnly" 1 "tmedge" } } */
