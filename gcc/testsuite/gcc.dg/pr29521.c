/* PR 29521 : warning for return with expression in function returning void */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

void func (void) { }

void func2 (void)
{
  return func ();
}

void func3 (void)
{
  return 1;  /* { dg-warning "'return' with a value" } */
}
