/* { dg-require-effective-target vla_in_struct } */
/* { dg-require-effective-target nested_func } */

int
main (int argc, char **argv)
{
  int size = 10;

  typedef struct {
    char val[size];
  } block;
  block retframe_block()
    {
      return *(block*)0;
    }

  return 0;
}
