/* PR c/35744 */
/* { dg-require-effective-target gcc_frontend } */

typedef char a[N] __attribute__((aligned(4))); /* { dg-error "undeclared" } */

void c[1] __attribute__((vector_size(8))); /* { dg-error "array of voids" } */

void b[1] __attribute__((may_alias)); /* { dg-error "array of voids" } */

struct A
{
  void d[1] __attribute__((packed)); /* { dg-error "array of voids" } */
};
