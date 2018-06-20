/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* Test that -Warray-bounds is enabled by -Wall */
/* { dg-options "-O2 -Wall" } */

int a[10];

int* f(void) {

    a[-1] = 0;             /* { dg-warning "array subscript" } */

    return a;
}

