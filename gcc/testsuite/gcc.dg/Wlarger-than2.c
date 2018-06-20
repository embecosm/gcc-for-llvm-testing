/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wlarger-than=8" } */
static void foo (void) 
{
  char buf[9]; /* { dg-warning "size of.*9 bytes" } */
}

