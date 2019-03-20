/* { dg-options "-funroll-loops -ftracer" } */
/* { dg-additional-options "-Wno-return-type" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
int a, b;

int f(void)
{
    (a % b) && f();
    a = (0 || a | (a ? : 1));
}
