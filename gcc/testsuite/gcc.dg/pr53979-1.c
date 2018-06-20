/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_internals } */

unsigned f1(unsigned a, unsigned b)
{
  return (a ^ b) | a; 
}

/* { dg-final { scan-tree-dump "a | b" "gimple" } } */
