/* { dg-do compile } */
/* { dg-options "-O2 " } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

int
test (unsigned short a, unsigned char b)
{
  return a > 0xfff2 && b > 252;
}

/* { dg-final { scan-assembler "ccmp" { target aarch64*-*-* } } } */
