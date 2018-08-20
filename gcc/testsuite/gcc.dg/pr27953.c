/* PR c/27953 */
/* { dg-require-effective-target gcc_frontend } */

void foo(struct A a) {} /* { dg-line foo_first } */
/* { dg-warning "declared inside parameter list" "inside" { target *-*-* } .-1 } */
/* { dg-error "incomplete type" "incomplete" { target *-*-* } .-2 } */

void foo() {}
/* { dg-error "redefinition" "redef" { target *-*-* } .-1 } */
/* { dg-message "note: previous definition" "previous" { target *-*-* } foo_first } */
