/* Verify diagnostics for extended identifiers refer to UCNs (in the C
   locale).  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c99" } */
/* { dg-require-ascii-locale "" } */
/* { dg-skip-if "" { "powerpc-ibm-aix*" } } */

void *p = &\u00e9; /* { dg-error "'\\\\U000000e9' undeclared" } */
void *q = &\u1e00; /* { dg-error "'\\\\U00001e00' undeclared" } */
