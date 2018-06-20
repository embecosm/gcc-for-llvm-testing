/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

unsigned b;
void f()
{
  for(;;)
    if(!b?:(b=0))
      ;
    else if(b%0<b?:b) /* { dg-warning "division by zero" } */
      for(;;)
	;
}
