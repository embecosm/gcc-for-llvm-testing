/* { dg-options "-ffat-lto-objects" } */
/* { dg-require-effective-target gcc_internals } */
int *
x(void)
{
 register int *a asm("unknown_register");  /* { dg-error "invalid register" } */
 int *v[1] = {a};
 return v[0];
}
