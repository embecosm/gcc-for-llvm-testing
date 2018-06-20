/* Test diagnostics for addresses of labels and computed gotos.  Test
   with -pedantic.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-pedantic" } */
/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target label_values } */

void
f (void)
{
  void *p = &&a; /* { dg-warning "taking the address of a label is non-standard" } */
  goto *p; /* { dg-warning "ISO C forbids 'goto \\*expr;'" } */
 a: ;
}
