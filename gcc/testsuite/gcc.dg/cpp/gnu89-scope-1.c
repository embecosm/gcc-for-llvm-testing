/* Test :: token in gnu89.  */
/* { dg-do preprocess } */
/* { dg-options "-std=gnu89 -pedantic-errors" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#define CONCAT(x, y) x ## y

CONCAT (:, :)
CONCAT (::, >) /* { dg-error "does not give a valid preprocessing token" } */
