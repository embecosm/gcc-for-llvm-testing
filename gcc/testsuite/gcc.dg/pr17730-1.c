/* Test formatting of message for invalid lvalue.  Bug 17730.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

char *p = &'C'; /* { dg-error "lvalue required as unary '&' operand" } */
