/* { dg-do compile } */
/* { dg-options "-freorder-blocks -ftracer} */
/* { dg-require-effective-target freorder } */

struct A {
    virtual A *f();
};
struct B : virtual A {
    virtual B *f();
};
B *B::f() { return 0; }
