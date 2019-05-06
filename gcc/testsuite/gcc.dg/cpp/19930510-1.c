/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

extern void exit (int);

#define ugly 3
#ugly "foobar" 3	/* { dg-error "invalid" "invalid directive" } */
int main() { exit (0); }
