/* PR/18160 */

/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

/* This should yield an error even without -pedantic.  */
/* { dg-options "-ansi" } */

void g(int *);

void f(void) 
{ 
  register int x;
  g(&x);	/* { dg-error "address of register variable" } */
} 
