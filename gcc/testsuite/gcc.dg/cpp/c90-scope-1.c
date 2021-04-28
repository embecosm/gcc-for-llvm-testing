/* Test :: token not in C90.  */
/* { dg-do preprocess } */
/* { dg-options "-std=c90 -pedantic-errors" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#define CONCAT(x, y) x ## y

CONCAT (:, :) /* { dg-error "does not give a valid preprocessing token" } */
