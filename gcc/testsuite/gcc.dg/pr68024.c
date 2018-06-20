/* PR c/68024 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void f (int, ...);
void f (a) int a; {} /* { dg-warning "defined as variadic function without prototype" } */
