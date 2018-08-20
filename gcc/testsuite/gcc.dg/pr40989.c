/* { dg-do compile } */
/* { dg-options "-Werror=implicit" } */
/* { dg-require-effective-target gcc_frontend } */
int main() {
  return pippo(); /* { dg-error "" } */
}
/* { dg-message "warnings being treated as errors" "" { target *-*-* } 0 } */
