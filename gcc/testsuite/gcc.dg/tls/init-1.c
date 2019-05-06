/* Invalid initializations.  */
/* { dg-require-effective-target tls } */
/* { dg-require-effective-target gcc_frontend } */

extern __thread int i;
int *p = &i;	/* { dg-error "initializer element is not constant" } */
