/* PR preprocessor/28709 */
/* 
   { dg-options "-ftrack-macro-expansion=2" }
   { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
*/

#define foo - ## >> /* { dg-error "pasting \"-\" and \">>\"" } */
foo
#define bar = ## == /* { dg-error "pasting \"=\" and \"==\"" } */
bar

