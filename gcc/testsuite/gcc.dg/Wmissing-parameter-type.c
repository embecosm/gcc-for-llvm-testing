/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wmissing-parameter-type" } */

int foo(bar) { return bar; } /* { dg-warning "type of 'bar' defaults to 'int'" } */


