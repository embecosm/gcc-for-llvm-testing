/* PR c/55570 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

char array[16] __attribute__((aligned (SOME_NOT_DEFINED_MACRO))); /* { dg-error "undeclared here" } */
