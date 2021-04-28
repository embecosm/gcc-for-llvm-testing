/* Tests for un-terminated conditionals: 1.  */
/* { dg-do preprocess } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#if 1  /* { dg-error "-:unterminated" "unterminated #if" } */

#ifdef notdef /* { dg-bogus "unterminated" "nested terminated #ifdef" } */

blah blah blah

#endif

more text

/* oops! */
