/* { dg-options "-Os -fdump-rtl-final" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

volatile unsigned char u8;

void test (void)
{
  u8 = u8 + u8;
  u8 = u8 - u8;
}

/* { dg-final { scan-rtl-dump-times "mem/v" 6 "final" } } */
