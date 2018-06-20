// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wc++-compat" }

#define not !  // { dg-warning "identifier \"not\" is a special operator name in C\\+\\+ .-Wc\\+\\+-compat." }
