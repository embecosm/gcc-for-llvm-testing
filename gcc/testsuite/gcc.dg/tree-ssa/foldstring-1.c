/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_frontend } */

void blah (void);

void
arf ()
{
  if (""[0] == 0)
    blah ();
}
/* { dg-final { scan-tree-dump-times "= 0;" 1 "gimple"} } */
