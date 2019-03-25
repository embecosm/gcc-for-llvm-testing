/* { dg-do assemble { target { ! { powerpc-ibm-aix* nvptx-*-* } } } } */
/* { dg-options "-fleading-underscore -funwind-tables" } */
/* { dg-require-effective-target gcc_frontend } */

void func(void) __asm("_func");
void _func(int x) {}
void func(void) {}

