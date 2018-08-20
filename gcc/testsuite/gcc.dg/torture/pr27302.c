/* { dg-do run } */
/* { dg-require-effective-target gcc_internals } */

extern void link_error (void);

void test0 (int a, int b)
{
  if ((a < b) != (b > a))
    link_error ();
}

int main()
{
  test0 (1, 2);
  return 0;
}
