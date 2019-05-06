/* Test for ICE after syntax error in initializer with range
   designator: PR 35446.  */
/* { dg-require-effective-target gcc_frontend } */

int a[2][2] = { [0 ... 1] = { ; } }; /* { dg-error "expected expression" } */
