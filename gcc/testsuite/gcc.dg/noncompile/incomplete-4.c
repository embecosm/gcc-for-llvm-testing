/* { dg-require-effective-target gcc_frontend } */
void foo()
{
  enum E e; /* { dg-error "storage size" } */
}
