/* { dg-require-effective-target gcc_frontend } */
struct a *q;
void
f()
{
  q++;	/* { dg-error "pointer to" } */
}
