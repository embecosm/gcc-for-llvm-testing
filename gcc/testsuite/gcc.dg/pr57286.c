/* { dg-do compile } */
/* { dg-options "-O" } */
/* { dg-require-effective-target gcc_frontend } */

typedef int vec __attribute__ ((vector_size (4*sizeof(int))));
void f (vec *x){
    *x = (*x < 0) | 1;
}
