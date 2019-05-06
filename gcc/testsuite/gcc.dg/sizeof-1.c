/* PR c/27718 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int i = sizeof(struct A[]);  /* { dg-error "incomplete" } */
