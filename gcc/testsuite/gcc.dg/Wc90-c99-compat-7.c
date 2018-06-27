/* { dg-do compile } */
/* { dg-options "-std=gnu90 -Wpedantic -Wc90-c99-compat -Wno-long-long -Wno-declaration-after-statement -Wno-vla" } */
/* { dg-require-effective-target gcc_frontend } */

long long l;

void
fn3 (int n)
{
  n = 3;
  int i;
}

void fn7 (int n, int a[n]);
