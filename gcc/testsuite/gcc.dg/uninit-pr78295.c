/* { dg-do compile } */
/* { dg-require-effective-target return_vector } */
/* { dg-options "-O2 -Wall -Wno-psabi" } */
/* { dg-additional-options "-Wno-unknown-warning-option" } */

typedef double vectype __attribute__ ((__vector_size__ (16)));

vectype
f (double x)
{
  vectype t;
  for (int i = 0; i < 2; i++)
    t[i] = x; /* { dg-bogus "uninitialized" } */
  return t;
}
