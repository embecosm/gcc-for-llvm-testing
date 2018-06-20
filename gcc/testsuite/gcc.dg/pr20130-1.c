/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */
int z (int a) {
	return a * -1;
}

int x (int a) {
	return -1 * a;
}

int y (int a) {
	return -(-1 * -a);
}
/* { dg-final { scan-tree-dump-times "-a" 3 "gimple" } } */
