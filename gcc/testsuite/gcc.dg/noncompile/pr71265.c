/* PR c/71265 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void ID (ID)
  int ID [__func__]; /* { dg-error "size of array .ID. has non-integer type" } */
{
}
