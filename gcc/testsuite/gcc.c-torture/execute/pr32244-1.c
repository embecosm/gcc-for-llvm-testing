/* It is implementation defined whether an operation on a bitfield of
   an implementation defined type has the declared type, or a type
   with the specified number of bits in the bitfield. GCC implements
   different behavior to other compilers.  */
/* { dg-require-effective-target gcc_frontend } */

struct foo
{
  unsigned long long b:40;
} x;

extern void abort (void);

void test1(unsigned long long res)
{
  /* The shift is carried out in 40 bit precision.  */
  if (x.b<<32 != res)
    abort ();
}

int main()
{
  x.b = 0x0100;
  test1(0);
  return 0;
}
