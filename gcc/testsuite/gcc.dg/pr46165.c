/* PR tree-optimization/46165 */
/* { dg-do compile } */
/* { dg-options "-O -fno-tree-ccp -fno-tree-copy-prop -fno-tree-dce" } */
/* { dg-require-effective-target gcc_internals } */

extern void foo (void) __attribute__((noreturn));
void
g (void)
{
  void (*f) (void) = foo;
  f ();
}
