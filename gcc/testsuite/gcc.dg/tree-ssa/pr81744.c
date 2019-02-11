/* { dg-do compile } */
/* { dg-options "-O3 -fno-tree-loop-vectorize -fno-tree-slp-vectorize -fno-inline -fdump-tree-pcom-details" } */
/* { dg-require-effective-target gcc_frontend } */

typedef struct {
  int a, b;
} CompandSegment;
int a;
CompandSegment *b;
void fn1() {
  for (; a; a++)
    b[a].a = b[a].b = b[a - 1].a = b[a - 1].b = 0;
}
/* { dg-final { scan-tree-dump-times "Store-stores chain" 2 "pcom"} } */
