/* { dg-do compile } */
/* { dg-options "-std=c89" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */
#define a b(
#define b(x) q
int aª);
