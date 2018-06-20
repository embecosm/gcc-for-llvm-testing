/* { dg-do compile } */
/* { dg-options "-O2 -funroll-loops -fweb -fdump-rtl-web" } */
/* { dg-require-effective-target gcc_internals } */

int
foo()
{
}

/* { dg-final { scan-rtl-dump-not "Web oldreg" "web" } } */
