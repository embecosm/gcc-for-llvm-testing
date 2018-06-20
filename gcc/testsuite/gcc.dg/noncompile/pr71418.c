/* PR c/71418 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

_Alignas (int) int a[7++]; /* { dg-error "lvalue required" } */
