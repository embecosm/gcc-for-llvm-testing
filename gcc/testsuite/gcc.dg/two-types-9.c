/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */

struct f {}
static int a, b; /* { dg-error "expected ';', identifier or " } */

int f()
{
	return a - b; /* { dg-bogus "invalid operands " } */
}
