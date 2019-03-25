/* { dg-do compile } */
/* { dg-options "-O -fipa-pta" } */
/* { dg-require-effective-target gcc_frontend } */

extern void a (void);

void b (void)
{
  void *c;
  c = a;
  *(char *)c = 1;
}
