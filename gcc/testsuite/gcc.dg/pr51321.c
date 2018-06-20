/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
int main ()
{
  return (__builtin_types_compatible_p (char[1][], char[1][1])); /* { dg-error "array type has incomplete element type" } */
}


