/* { dg-require-effective-target gcc_frontend } */
struct a { char *b; } c[D]; /* { dg-error "undeclared" } */
