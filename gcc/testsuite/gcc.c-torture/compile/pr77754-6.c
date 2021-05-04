/* PR c/77754 */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target vla_in_struct } */

int fn3();

void fn4(int (*)[fn3 ()][fn3 () + 1][fn3 () + 2], struct S { int a[fn3 ()]; } *);

void fn1() {
  int a[10][fn3 ()][fn3 () + 1][fn3 () + 2];
  fn4 (a, 0);
}
