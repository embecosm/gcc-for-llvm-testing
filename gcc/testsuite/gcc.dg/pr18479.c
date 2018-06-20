/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */
struct __attribute__ ((visibility("default"))) Foo { int foo; }; /* { dg-warning "attribute ignored on types" } */
