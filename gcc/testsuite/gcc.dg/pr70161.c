/* { dg-do compile } */
/* { dg-options "-O2 -fdump-ipa-all-graph" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (void)
{
}

/* { dg-final { scan-ipa-dump-times "subgraph" 1 "inline.dot" } } */
/* { dg-final { scan-ipa-dump-times "subgraph" 1 "cp.dot" } } */
