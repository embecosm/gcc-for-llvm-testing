/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -fgnu89-inline" } */
inline __attribute__ ((always_inline)) void t(void); /* { dg-error "body not available" } */
void
q(void)
{
  t(); 				/* { dg-message "called from here" } */
}
