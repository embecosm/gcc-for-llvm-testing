/* PR middle-end/13448 */

/* { dg-options "-O3" } */
/* { dg-require-effective-target gcc_frontend } */

void funct (const int n)
{
  n++; /* { dg-error "" } */
}

int main () {
  funct (1);
  return 0;
}
