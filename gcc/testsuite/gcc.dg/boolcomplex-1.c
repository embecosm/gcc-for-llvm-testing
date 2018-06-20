/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */
_Bool b = --0i == 0; /* { dg-error "lvalue required as decrement operand" } */
