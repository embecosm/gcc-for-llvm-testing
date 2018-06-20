/*
  { dg-options "-fshow-column -ftrack-macro-expansion=2" }
  { dg-do compile }
/* { dg-require-effective-target gcc_frontend } */
 */

#define SQUARE(A) A * A	 /* { dg-message "in definition of macro 'SQUARE'" } */

void
foo()
{
  SQUARE (1 << 0.1);  /* { dg-message "13:invalid operands to binary <<" } */
}

