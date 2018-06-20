/* PR tree-optimization/69483 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct T { struct S *a; };
struct S b; /* { dg-error "storage size of 'b' isn't known" } */
struct T c = { &b };
