/* { dg-require-effective-target gcc_frontend } */
struct a
{
  struct b t;	/* { dg-error "has incomplete type" } */
};
