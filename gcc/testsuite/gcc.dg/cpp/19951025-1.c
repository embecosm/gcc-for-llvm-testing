/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "include expects" "include" { target *-*-* } .+2 } */
/* { dg-error "newline at end" "newline" { target *-*-* } .+1 } */
#include /\
