/* Parse error recovery
{ dg-do compile }
/* { dg-require-effective-target gcc_frontend } */
{ dg-options "-fsyntax-only" }
*/

void f(int x)
{
  if (x > 1)
    int ret = 1; /* { dg-error "expected expression before 'int'" } */

}
