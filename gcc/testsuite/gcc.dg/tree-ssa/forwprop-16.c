/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-forwprop1" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (double xx, double xy)
{
  int p = xx < xy;
  int np = !p; 
  if (np)
    return 5;
  return 2;
}

/* { dg-final { scan-tree-dump "if \\\(x" "forwprop1" } } */
