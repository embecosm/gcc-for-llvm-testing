/* PR c/71362 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

extern void foo (int[-1]); /* { dg-error "21:size of unnamed array is negative" } */

int
bar (void)
{
  123 + sizeof (int[-1]); /* { dg-error "20:size of unnamed array is negative" } */
}
