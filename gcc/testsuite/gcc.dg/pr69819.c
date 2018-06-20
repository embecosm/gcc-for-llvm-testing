/* PR c/69819 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo () { }
int foo[] = { 0 }; /* { dg-error ".foo. redeclared as different kind of symbol" } */
