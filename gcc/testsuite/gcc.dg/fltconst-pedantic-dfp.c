/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-pedantic" } */

double a = 1.dl;	/* { dg-warning "decimal float" } */
double b = 1.df;	/* { dg-warning "decimal float" } */
double c = 1.dd;	/* { dg-warning "decimal float" } */
