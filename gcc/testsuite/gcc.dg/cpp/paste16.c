/* Test multiple consecutive ## tokens.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */
#define cat(x,y) x##########y
int abcd;
int *p = &cat(ab,cd);
