/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-mtune=*" } { "" } } */
/* { dg-options "-mtune=foo" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "mtune" "mtune" { target *-*-* } 0 } */
/* { dg-bogus "march" "march" { target *-*-* } 0 } */
/* { dg-bogus "mcpu" "mcpu" { target *-*-* } 0 } */
/* { dg-prune-output "note: valid arguments.*" } */
int i;
