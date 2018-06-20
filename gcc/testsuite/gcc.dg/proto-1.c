/* PR c/28502 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo() {}      /* { dg-message "note: previous" } */
void foo(void[]);  /* { dg-error "array of voids" } */
