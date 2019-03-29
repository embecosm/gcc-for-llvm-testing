/* { dg-do compile } */
/* { dg-options "--param ggc-min-expand=0 --param ggc-min-heapsize=0" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */

int g ();
static __inline__ int f () { return g (); }
int g () { return f (); }
