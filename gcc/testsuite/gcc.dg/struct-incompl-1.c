/* PR c/26818 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct __attribute__ ((packed)) A
{
  struct B b; /* { dg-error "incomplete" } */
};
