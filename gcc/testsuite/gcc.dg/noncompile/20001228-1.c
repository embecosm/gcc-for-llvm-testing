/* { dg-require-effective-target gcc_frontend } */
void rof(void)
{
  union { int a; } u;
  for (u.a = 0; u; u.a++)  /* { dg-error "used union" } */
    ;
}
