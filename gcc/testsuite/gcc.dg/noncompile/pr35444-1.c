/* PR 35444: ICE from pending VLA sizes in invalid parameter list.  */
void foo(int n, int a[n], int 0); /* { dg-error "expected" } */
/* { dg-require-effective-target gcc_frontend } */
void bar() {}
