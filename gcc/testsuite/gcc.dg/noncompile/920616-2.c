/* { dg-require-effective-target gcc_frontend } */
void f(void a,...){}		/* { dg-error "has incomplete type" } */
