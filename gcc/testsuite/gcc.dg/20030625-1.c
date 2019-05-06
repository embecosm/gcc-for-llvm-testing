/* Testcase from http://gcc.gnu.org/ml/gcc-patches/2003-06/msg02557.html */
/* { dg-do compile } */
/* { dg-options "-g" } */
/* { dg-require-effective-target gcc_frontend } */

typedef struct _foo foo;
struct _foo {
  struct _moo moo;	/* { dg-error "moo" "has incomplete type" } */
};

