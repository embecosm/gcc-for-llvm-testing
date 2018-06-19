/* { dg-require-effective-target vla_in_struct } */

/* PR c/5615 */
void f(int a, struct {int b[a];} c) {}
