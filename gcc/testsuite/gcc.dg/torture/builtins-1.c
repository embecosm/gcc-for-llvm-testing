/* { dg-do compile } */
/* { dg-options "-fdump-rtl-expand-all" } */
/* { dg-require-effective-target gcc_internals } */
int isdigit(int c)
{
        return c >= 0;
}


