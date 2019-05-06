/* PR preprocessor/27777 */
/* { dg-do preprocess } */
/* { dg-options { -trigraphs -Wall } } */
/* { dg-require-effective-target gcc_frontend } */

#error "BUG??!"
/* { dg-error "BUG" "" { target *-*-* } .-1 } */
/* { dg-warning "trigraph" "" { target *-*-* } .-2 } */
