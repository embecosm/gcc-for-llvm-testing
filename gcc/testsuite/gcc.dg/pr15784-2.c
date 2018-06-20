/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple -ffast-math" } */
/* { dg-require-effective-target gcc_internals } */
/* Test for folding abs(x) where appropriate.  */
#define abs(x) x > 0 ? x : -x
extern double fabs (double);

int a (float x) {
	return fabs(x) >= 0.0;
}

/* { dg-final { scan-tree-dump-times "ABS_EXPR" 0 "gimple" } } */
