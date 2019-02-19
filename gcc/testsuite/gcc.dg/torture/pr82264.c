/* { dg-do compile } */
/* { dg-additional-options "-Wno-return-type" } */
/* { dg-additional-options "-Wno-builtin-requires-header" } */

char a;
int c;
unsigned b ();
unsigned
setjmp ()
{
}
static void
d ()
{
  if (b ())
    c = 3;
}
void
e ()
{
  d ();
  a && ({ setjmp (); });
}
