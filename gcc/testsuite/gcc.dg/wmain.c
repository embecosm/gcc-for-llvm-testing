/* { dg-do compile } */
/* { dg-options "-Wall" } */
/* { dg-require-effective-target gcc_frontend } */

int main; /* { dg-warning "'main' is usually a function" } */

int foo()
{
  int main = 1; /* { dg-bogus "'main' is usually a function" } */
  return main;
}
