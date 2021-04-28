/* PR c/99325 */
/* { dg-do preprocess } */
/* { dg-options "-pedantic" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#line 4294967295	/* { dg-warning "line number out of range" } */
#pragma message "foo"
