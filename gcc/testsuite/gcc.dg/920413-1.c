/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wtraditional -std=gnu89" } */

int
x (b)
{
  return
  4294967295U   /* { dg-warning "width of integer|traditional C rejects" } */
   / (unsigned long) b;
}
