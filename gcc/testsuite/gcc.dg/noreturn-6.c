/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* Check for volatile behavior.  */
extern int xxx (void);
volatile extern int xxx (void);  /* { dg-error "not compatible" } */
