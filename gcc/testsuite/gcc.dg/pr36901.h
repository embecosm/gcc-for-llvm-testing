/* { dg-additional-options "-Wno-error" } */
/* { dg-additional-options "-Wno-pedantic" } */
/* { dg-require-effective-target gcc_frontend } */
int sc = (&sc >= 0);

