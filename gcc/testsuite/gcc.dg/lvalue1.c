/* PR c/5225 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int main()
{
  int i;
  +i = 1;	/* { dg-error "lvalue required as left operand of assignment" } */
  return 0;
}
