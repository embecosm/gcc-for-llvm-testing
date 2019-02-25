/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-unused-comparison" } */
void foo()
{
    L:
    &&L != 0;
}

