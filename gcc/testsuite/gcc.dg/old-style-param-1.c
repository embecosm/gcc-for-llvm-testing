/* PR c/35750 */
/* { dg-require-effective-target gcc_frontend } */

void foo(int[]);
void foo(x) int x[](); {} /* { dg-error "array of functions" } */
