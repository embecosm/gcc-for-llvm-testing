/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-pre-stats" } */
/* We can't eliminate the *p load here in any sane way, as eshup8 may 
   change it.  */
/* { dg-require-effective-target gcc_frontend } */

void eshup8 (unsigned short *);

void
enormlz (x)
     unsigned short x[];
{
  register unsigned short *p;
  p = &x[2];
  while ((*p & 0xff00) == 0)
    {
      eshup8 (x);
    }
}
/* { dg-final { scan-tree-dump-not "Eliminated:" "pre"} } */
