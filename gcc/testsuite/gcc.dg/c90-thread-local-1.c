/* Test for _Thread_local: not in C90.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c90 -pedantic-errors" } */

static _Thread_local int x; /* { dg-error "_Thread_local" } */
