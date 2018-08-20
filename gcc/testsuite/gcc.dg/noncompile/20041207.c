/* PR18867 - ICE on a switch controlling expressions with an
   invalid type.  Origin: Serge Belyshev <belyshev@lubercy.com>  */
/* { dg-require-effective-target gcc_frontend } */
   
void f()
{
  float x;
  switch (x) {case 0: break;}; /* { dg-error "not an integer" } */
}
