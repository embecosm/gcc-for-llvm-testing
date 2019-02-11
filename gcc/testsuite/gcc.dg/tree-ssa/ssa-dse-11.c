/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-dse1-details" } */
/* { dg-require-effective-target gcc_frontend } */

extern void abort(void);
void foo(int *p)
{
  while (1)
   {
      *p = 1;
      *p = 0;
   }
}
void bar(int *p)
{
  *p = 1;
  *p = 0;
  abort ();
}

/* { dg-final { scan-tree-dump-times "Deleted dead store" 2 "dse1" } } */
