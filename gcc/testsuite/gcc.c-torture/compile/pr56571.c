/* { dg-options "-funroll-loops -ftracer" } */
/* { dg-additional-options "-Wno-return-type" } */
int a, b;

int f(void)
{
    (a % b) && f();
    a = (0 || a | (a ? : 1));
}
