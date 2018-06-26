/* { dg-do run } */
/* { dg-options "-fno-tree-dce" } */
/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
/* { dg-require-effective-target vla_in_struct } */
/* { dg-require-effective-target gcc_internals } */

static inline int foo (int n, int k)
{
  struct S
  {
    int i[n];
    int value;
  } s[2];
  return s[k].value = 0;
}

int main ()
{
  return foo (2, 0);
}
