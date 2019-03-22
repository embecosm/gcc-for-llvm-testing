/* { dg-do compile } */
/* { dg-options "-O0" } */
/* { dg-final { scan-assembler "debug_hook" } } */
/* { dg-additional-options "-Wno-return-type" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
static int debug_hook()
{
}
