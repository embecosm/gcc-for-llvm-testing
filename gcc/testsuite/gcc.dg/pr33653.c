/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-shorten" } */
/* { dg-require-effective-target gcc_internals } */

void f (volatile char *p)
{
  char c = p[0];
}

/* { dg-final { scan-rtl-dump "mem/v" "shorten" } } */
