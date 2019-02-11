/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

volatile int count;
int arr[4];
void foo()
{
 arr[count++] = 0;
}

/* { dg-final { scan-tree-dump-times "count =" 1 "optimized"} } */

