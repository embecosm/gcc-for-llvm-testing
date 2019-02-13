/* { dg-do compile } */
/* { dg-additional-options "-Wno-return-type" } */

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
