/* { dg-require-effective-target nested_func } */
void baz(int i);

void foo(int i, int A[i+1])
{
    int j=A[i];
    void bar() { baz(A[i]); }
}
