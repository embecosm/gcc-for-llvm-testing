/* { dg-do compile } */
/* { dg-options "-O2 -std=c99" } */
/* { dg-additional-options "-Wno-int-conversion" } */

void
foo (void)
{
  char *e = alloca (100); /* { dg-warning "implicit declaration|initialization of 'char \\*' from 'int' makes" } */
}
