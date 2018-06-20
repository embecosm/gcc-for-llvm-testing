// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wunused-macros" }

#define X X  // { dg-warning "-:macro \"X\" is not used .-Wunused-macros." }
