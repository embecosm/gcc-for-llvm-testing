/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void __attribute__((dj)) foo() { }	/* { dg-warning "attribute directive ignored" } */

int j __attribute__((unrecognized));	/* { dg-warning "attribute directive ignored" } */
