/* { dg-require-effective-target gcc_frontend } */
void a (void x) {}	/* { dg-error "has incomplete type" } */
