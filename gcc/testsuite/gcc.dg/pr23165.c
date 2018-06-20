/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wempty-body" } */
void foo (void)
{
	if (0)
	  a: ; /* { dg-warning "empty body in an" } */


}
