/* PR c/37106 */
/* { dg-do compile } */
/* { dg-options "-O1" } */
/* { dg-options "-O1 -fpic" { target fpic } } */
/* { dg-additional-options "-Wno-unknown-attributes" } */

#define SIZE 256
float a[SIZE], b[SIZE], c[SIZE];

void opt3 (void) __attribute__((__optimize__(3)));

void
opt3 (void)
{
  int i;

  for (i = 0; i < SIZE; i++)
    a[i] = b[i] + c[i];
}

void
not_opt3 (void)
{
  int i;

  for (i = 0; i < SIZE; i++)
    a[i] = b[i] - c[i];
}
