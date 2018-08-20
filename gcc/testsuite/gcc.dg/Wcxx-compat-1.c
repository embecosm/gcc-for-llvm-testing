/* PR c/21759  */
/* { dg-options "-Wc++-compat" } */
/* { dg-require-effective-target gcc_frontend } */

int
main(void)
{
   void *p = 0;
   int *q = p;                  /* { dg-warning "not permitted" } */
   double* t = (void *)0;
   return p != q;
}
