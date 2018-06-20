/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-w" } */


int foo(int x)
{
  switch(x)
  {

  case 0 % 0:	 /* { dg-error "case label does not reduce to an integer constant" } */
    return 1;
  default:
    return 2;
  }
}
