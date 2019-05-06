/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

/* Check for application of ~ on vector types.  */

#define vector __attribute__((vector_size(16) ))

vector float a;
vector int a1;

void f(void)
{
 a =  ~a; /* { dg-error "" } */
 a1 =  ~a1;
}
