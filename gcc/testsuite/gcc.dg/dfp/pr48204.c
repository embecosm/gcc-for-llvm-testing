/* PR debug/48204 */
/* { dg-do compile } */
/* { dg-options "-O -fno-tree-ccp -fno-tree-dominator-opts -fno-tree-fre -g" } */
/* { dg-require-effective-target gcc_frontend } */

void
foo (void)
{
  float cf = 3.0f;
  _Decimal64 d64 = cf;
}
