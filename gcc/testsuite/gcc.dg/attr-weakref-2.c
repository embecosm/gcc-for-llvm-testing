/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-require-weak "" } */

typedef int vtype;

extern vtype wv1;
extern vtype Wv1a __attribute__((weakref ("wv1"))); /* { dg-error "'weakref' symbol 'Wv1a' must have static linkage" } */
