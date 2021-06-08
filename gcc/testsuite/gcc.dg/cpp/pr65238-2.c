/* PR preprocessor/65238 */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */

#if __has_attribute(
#endif
#if __has_attribute(unused
#endif
#if __has_attribute(unused, unused)
#endif
#if __has_attribute(__has_attribute(unused))
#endif

/* { dg-error "macro .__has_attribute. requires an identifier" "" {target "*-*-*"} 5 } */
/* { dg-error "missing ... after .__has_attribute." "" {target "*-*-*"} 7 } */
/* { dg-error "missing ... after .__has_attribute." "" {target "*-*-*"} 9 } */
/* { dg-error "missing binary operator before token .unused." "" {target "*-*-*"} 9 } */
/* { dg-error "macro .__has_attribute. requires an identifier" "" {target "*-*-*"} 11 } */
/* { dg-error "missing ... in expression" "" {target "*-*-*"} 11 } */
