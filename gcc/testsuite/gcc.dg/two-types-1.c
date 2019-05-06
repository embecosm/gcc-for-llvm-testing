/* { dg-do compile } */
/* { dg-options "-std=gnu89" } // suppress default -pedantic-errors */
/* { dg-require-effective-target gcc_frontend } */

typedef int x, y;
x y z;			/* { dg-error "" } */
