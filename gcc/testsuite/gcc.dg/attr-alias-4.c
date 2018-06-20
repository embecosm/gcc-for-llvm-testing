/* ICE on invalid alias attribute: PR 35434.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */
typedef int i __attribute__((alias("j"))); /* { dg-warning "ignored" } */
