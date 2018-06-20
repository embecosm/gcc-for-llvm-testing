/* PR c/63567 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wpedantic" } */

struct T { int i; };
struct S { struct T t; };
struct S s = { .t = { (int) { 1 } } }; /* { dg-warning "initializer element is not constant" } */
