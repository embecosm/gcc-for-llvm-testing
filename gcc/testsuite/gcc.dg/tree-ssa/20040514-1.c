/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-phiopt2-details" } */
/* { dg-require-effective-target gcc_frontend } */

int t( int i)
{
  int j;
  if(i ==0)
  {
   j = 1;
   goto end;
  }
  j = 0;
end:
  return j;
}

/* Should have no ifs left after straightening.  */
/* { dg-final { scan-tree-dump-times "if " 0 "phiopt2"} } */
