/* { dg-do compile } */
/* { dg-options "--completion=-flto-parti" } */
/* { dg-require-effective-target gcc_frontend } */

/* { dg-begin-multiline-output "" }
-flto-partition=1to1
-flto-partition=balanced
-flto-partition=max
-flto-partition=none
-flto-partition=one
-flto-partition=
   { dg-end-multiline-output "" } */
