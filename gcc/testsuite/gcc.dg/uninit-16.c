/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wuninitialized" } */

int foo, bar;

static
void decode_reloc(int reloc, int *is_alt)
{
  if (reloc >= 20)
      *is_alt = 1;
  else if (reloc >= 10)
      *is_alt = 0;
}

void testfunc()
{
  int alt_reloc;

  decode_reloc(foo, &alt_reloc);

  if (alt_reloc) /* { dg-warning "may be used uninitialized" } */
    bar = 42;
}
