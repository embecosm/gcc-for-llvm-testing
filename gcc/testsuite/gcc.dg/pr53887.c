/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-unused-value" } */

enum
{ Failed, NoError, NoDiskette }
a;
int b, c;
void
fn1 ()
{
    if (c)
        a << 1;
    switch (b)
    {
    default:
        a << 1;
    case 0:
        b = 0;
    case 1:
    case NoDiskette:
        ;
    }
}

