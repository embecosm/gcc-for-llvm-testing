// { dg-options "-Wsized-deallocation" }
/* { dg-require-effective-target builtin_free } */

void operator delete (void *p) throw() { __builtin_free(p); } // { dg-warning "sized" "" { target c++14 } }
