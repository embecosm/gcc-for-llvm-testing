/* PR preprocessor/28709 */
/* 
   { dg-options "-ftrack-macro-expansion=0" }
   { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
*/

#define foo - ## >>
foo		/* { dg-error "pasting \"-\" and \">>\"" } */
#define bar = ## ==
bar		/* { dg-error "pasting \"=\" and \"==\"" } */
