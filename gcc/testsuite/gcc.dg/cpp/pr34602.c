/* PR preprocessor/34602 - no internal error trying to spell EOF.  */
/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */

/* { dg-error "unexpected end" "" { target *-*-* } .+1 } */
#line
