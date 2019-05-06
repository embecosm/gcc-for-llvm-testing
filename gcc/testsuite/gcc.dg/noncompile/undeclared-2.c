/* Invalid, but should not ICE.  PRs 11944, 14734.  */
/* { dg-require-effective-target gcc_frontend } */

void foo(const int[i]);  /* { dg-error "undeclared|for each" } */
