/* Tests for unterminated conditionals: 3.  */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */

#if 1  /* { dg-error "-:#else" "unterminated #else" } */
#else
