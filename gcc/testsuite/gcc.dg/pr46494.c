/* { dg-do compile }
/* { dg-options "-O -fno-tree-ccp -fno-tree-fre -ftree-vrp" } */
/* { dg-require-effective-target gcc_internals } */

extern void foo (void) __attribute__((noreturn));
void g (void)
{
  void (*f) (void) = foo;
  f ();
}
