/* { dg-do compile } */
/* { dg-options "-O -fdata-sections" } */
/* { dg-skip-if "-fdata-sections not supported" { hppa*-*-hpux* nvptx-*-* } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

int x = 1;
int x;

/* { dg-final { scan-assembler-not {comm[\t ]+x} } } */
