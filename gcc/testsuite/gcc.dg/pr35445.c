/* PR c/35445 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

extern int i;
extern int i; /* { dg-message "previous declaration of 'i'" } */
int i[] = { 0 }; /* { dg-error "conflicting types" } */
