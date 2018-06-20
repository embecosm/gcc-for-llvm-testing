/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wuninitialized" } */

int sys_msgctl (void)
{
  struct { int mode; } setbuf;
  return setbuf.mode; /* { dg-warning "'setbuf\.mode' is used uninitialized" } */
}
