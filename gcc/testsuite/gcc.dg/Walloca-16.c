/* PR tree-optimization/84224 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O0 -Walloca" } */

void *alloca ();
__typeof__(alloca ()) a () { return alloca (); }
