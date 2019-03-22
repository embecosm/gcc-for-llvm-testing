/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

void f()
{
  asm ("foo%%bar");
}

/* { dg-final { scan-assembler "foo%%bar" } } */
