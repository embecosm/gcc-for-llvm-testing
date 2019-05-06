// { dg-do preprocess }
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wmultichar" }
/* { dg-require-effective-target gcc_frontend } */

#if 'ab'  // { dg-warning "multi-character character constant .-Wmultichar." }
#endif
