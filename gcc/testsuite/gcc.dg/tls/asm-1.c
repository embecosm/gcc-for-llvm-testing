/* { dg-options "-Werror" } */
/* { dg-require-effective-target tls } */
/* { dg-require-effective-target gcc_frontend } */
__thread int i;

int foo ()
{
  asm volatile ("" :: "m" (&i));  /* { dg-error "directly addressable" } */
}
