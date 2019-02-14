/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-unused-value" } */
void foo()
{
    L:
    !&&L;
}

