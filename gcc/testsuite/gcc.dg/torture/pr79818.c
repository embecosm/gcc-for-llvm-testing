/* { dg-do run } */
/* { dg-additional-options "-fwrapv" } */
/* { dg-require-effective-target noclone } */

static void __attribute__((noinline,noclone))
func(void)
{
  signed char c = 0;

  for(; c >= 0; c++);

  if(c != -128)
    __builtin_abort();
}

int main(int argc, char* argv[])
{
  func();
  return 0;
}
