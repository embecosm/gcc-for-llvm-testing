/* Ensure that diagnostics for labels appear on the correct lineno.
   by Kaveh R. Ghazi <ghazi@caip.rutgers.edu> 8/23/2000.  */
/* { dg-require-effective-target gcc_frontend } */

void
foo(int i)
{
 my_label: /* { dg-message "note: previous definition" "prev label" } */

  i++;

 my_label: /* { dg-error "duplicate label" "label lineno" } */

  i++;
}
