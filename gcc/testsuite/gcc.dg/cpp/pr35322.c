/* Test case for PR 35322 -- _Pragma ICE.  */

/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
_Pragma("GCC dependency") /* { dg-error "#pragma dependency expects" } */
