/* PR optimization/6871 */
/* Constant variables belong in .rodata, not .bss.  */
/* { dg-final { scan-assembler-not "\.bss" } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

const int i = 0;
