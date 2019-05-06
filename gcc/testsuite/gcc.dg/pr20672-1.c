/* EOF must cause an error inside a function, not just set parser->error.
   Bug 20672.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */
int main(void)
{
int a; /* { dg-error "expected" } */
