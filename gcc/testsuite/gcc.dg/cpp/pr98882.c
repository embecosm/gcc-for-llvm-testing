/* PR preprocessor/98882 */
/* { dg-do preprocess } */
/* { dg-options "-fdirectives-only" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

/* Last line does not end with a newline.  */
    /*Here*/
