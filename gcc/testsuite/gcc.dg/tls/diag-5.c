/* __thread specifiers on empty declarations.  */
/* { dg-require-effective-target tls } */
/* { dg-require-effective-target gcc_frontend } */

__thread struct foo; /* { dg-warning "useless '__thread' in empty declaration" } */
