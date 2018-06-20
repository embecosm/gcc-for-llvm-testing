/* PR c/65066 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wformat -Wformat-signedness" } */

extern int sscanf (const char *restrict, const char *restrict, ...);
int *a;

void
foo ()
{
  sscanf (0, "0x%x  #", a); /* { dg-warning "expects argument of type" } */
}
