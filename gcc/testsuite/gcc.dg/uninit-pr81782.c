/* { dg-do compile } */
/* { dg-options "-Wmaybe-uninitialized" } */
/* { dg-require-effective-target gcc_frontend } */

int
foo (void)
{
  char empty_array[] = { };
  int i, ret = 0;

  for (i = 0; i < (int) (sizeof (empty_array) / sizeof (empty_array[0])); i++)
    ret = empty_array[i]; /* { dg-bogus "uninitialized" } */

  return ret;
}
