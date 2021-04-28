/* PR c/99325 */
/* { dg-do preprocess } */
/* { dg-options "-pedantic" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#line 9223372036854775807	/* { dg-warning "line number out of range" } */
#pragma message "foo"
