/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target gcc_frontend } */

void* a;

void foo() {
    if ((a = &&l))
        return;

    l:;
}

int main() {
    foo();
    goto *a;

    return 0;
}
