/* PR c/71426 */
/* { dg-do compile } */
/* { dg-options "-w" } */
/* { dg-require-effective-target gcc_frontend } */

int f (int x[x - x ()]); /* { dg-error "undeclared" } */
