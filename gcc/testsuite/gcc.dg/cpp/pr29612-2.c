/* PR preprocessor/29612 */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wtraditional" } */

# 7 "pr29612-2.c"

#if 1U /* { dg-warning "traditional C rejects" "numeric constant suffix" } */
#endif

# 1 "foo.h" 1 3

#if 1U
#endif /* No warning in system header.  */

# 17 "pr29612-2.c" 2

#if 1U /* { dg-warning "traditional C rejects" "numeric constant suffix" } */
#endif
