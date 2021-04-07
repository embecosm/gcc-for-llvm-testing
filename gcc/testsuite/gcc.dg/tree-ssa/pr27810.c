/* { dg-do compile } */
/* { dg-options "-fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_frontend } */

int bar (int);

int qqq (int a)
{
    int result;
    result = bar (a);
    return result;
}

/* We should not use an extra temporary for the result of the
   function call.  */

/* { dg-final { scan-tree-dump-times "int" 4 "gimple" } } */
/* { dg-final { scan-tree-dump-times "int D\\\." 1 "gimple" } } */
