/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */
void
f (void)
{
  int x;
  asm ("" :  "" (x)); /* { dg-error "output operand constraint lacks" } */
}
