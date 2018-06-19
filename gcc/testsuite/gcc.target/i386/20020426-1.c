/* { dg-do compile } */
/* { dg-require-effective-target ilp32 } */
/* { dg-require-effective-target builtin_apply } */
/* { dg-options "-msoft-float -mfp-ret-in-387" } */

void f() {
  __builtin_apply(0, 0, 0);
}
