/* { dg-do compile } */
/* { dg-prune-output "conflicting types for built-in" } */
/* { dg-require-effective-target gcc_internals } */

extern void *memcpy();
int main() { memcpy(); }

/* { dg-prune-output "\\\[-Wbuiltin-declaration-mismatch]" } */
