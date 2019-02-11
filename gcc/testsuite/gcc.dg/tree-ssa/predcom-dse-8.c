/* { dg-do run } */
/* { dg-options "-O2 -fno-inline -fpredictive-commoning -fdump-tree-pcom-details" } */
/* { dg-require-effective-target gcc_frontend } */

int arr[105] = {2, 3, 5, 7, 11, 13, 17, 19};
int result0[10] = {2, 3, 5, 7, 11, 13, 17, 19};
int result1[10] = {0, 3, 5, 7, 11, -5, 17, 19};
int result2[10] = {0, 0, 5, 7, 11, -5, -5, 19};
int result3[10] = {0, 0, 0, 7, 11, -5, -5, -5};
int result4[10] = {0, 0, 0, 0, 11, -5, -5, -5, -5};
int result100[105] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, -5, -5, -5, -5};

extern void abort (void);

void __attribute__((noinline)) foo (int *a, int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      a[i] = 0;
      a[i + 5] = -5;
    }
}

void check (int *a, int *res, int len)
{
  int i;

  for (i = 0; i < len; i++)
    if (a[i] != res[i])
      abort ();
}

int main (void)
{
  foo (arr, 0);
  check (arr, result0, 10);

  foo (arr, 1);
  check (arr, result1, 10);

  foo (arr, 2);
  check (arr, result2, 10);

  foo (arr, 3);
  check (arr, result3, 10);

  foo (arr, 4);
  check (arr, result4, 10);

  foo (arr, 100);
  check (arr, result100, 105);

  return 0;
}
