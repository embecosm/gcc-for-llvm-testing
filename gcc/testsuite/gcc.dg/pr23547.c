/* { dg-do compile } */
/* { dg-options "--param ggc-min-expand=0 --param ggc-min-heapsize=0" } */
/* { dg-require-effective-target nested_func } */
void foo()
{
  void bar()
  {
    bar();
  }
}

void foo1(int i)
{
    void bar (char c[1][i]) { }
}
