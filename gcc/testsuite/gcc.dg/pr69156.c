/* PR tree-optimization/69156 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O1 -fno-tree-ccp" } */

_Bool
foo ()
{
  _Bool (*f) () = __builtin_abs;	/* { dg-warning "initialization of '_Bool \\(\\*\\)\\(\\)' from incompatible pointer type" } */
  return f (0);
}
