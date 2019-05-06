/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void f () __attribute__ ((__malloc__)); /* { dg-warning "ignored" } */

int main ()
{
	/* This used to cause an ICE.  */
	f ();
}

