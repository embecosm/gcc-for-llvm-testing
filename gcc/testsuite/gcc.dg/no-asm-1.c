/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } */

/* Verify that these GNU extensions are recognized as keywords in
   GNU89 mode.  */

int asm;	/* { dg-error "before .asm." } */
int inline;	/* { dg-warning "empty declaration" } */
/* { dg-error "empty declaration" "" { target *-*-* } .-1 } */
int typeof;	/* { dg-error "before .typeof." } */
