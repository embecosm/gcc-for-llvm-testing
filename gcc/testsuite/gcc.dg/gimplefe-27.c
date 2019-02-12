/* { dg-options "-O -fgimple" } */
/* { dg-require-effective-target gcc_frontend } */

int __GIMPLE ()
p (int n)
{
  int _2;
  _Bool _3;
  _3 = n_1(D) != 0;
  _2 = _3 ? 2 : 0;
  return _2;
}
