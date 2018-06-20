// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wundef" }

#if x  // { dg-warning "\"x\" is not defined, evaluates to 0 .-Wundef." }
#endif
