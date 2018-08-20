/* { dg-do compile } */
/* { dg-require-weak "" } */
/* { dg-require-effective-target gcc_frontend } */
#pragma weak int = foo

/* { dg-warning "declaration of" "weak" { target *-*-* } 0 } */
