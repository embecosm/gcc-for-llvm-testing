/* { dg-do compile } */
/* { dg-require-effective-target gcc_internals } */

extern void *memcpy();
int main() { memcpy(); }
