/* { dg-do compile } */
/* { dg-additional-options "-Wno-incompatible-library-redeclaration" } */

extern void *memmove(void *, void *, __SIZE_TYPE__);
typedef int (*_TEST_fun_) ();
static _TEST_fun_ i = (_TEST_fun_) memmove;
int main() { i(); }
