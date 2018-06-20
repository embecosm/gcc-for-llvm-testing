/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */

int f()
{
  struct f {
  }
  int z; /* { dg-error "expected ';', identifier or " } */
}
