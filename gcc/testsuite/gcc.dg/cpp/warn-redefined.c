// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wbuiltin-macro-redefined" }

#ifndef __TIME__
#error "__TIME__ builtin is not defined"
// { dg-bogus "__TIME__ builtin is not defined" "no-time" { target *-*-* } .-1 }
#endif

#define __TIME__ "X"  // { dg-warning "-:\"__TIME__\" redefined .-Wbuiltin-macro-redefined." }

#define __TIME__ "Y"  // { dg-bogus "-Wbuiltin-macro-redefined" }
                      // { dg-warning "-:\"__TIME__\" redefined" "not-builtin-1" { target *-*-* } .-1 }
                      // { dg-message "-:previous definition" "previous-1" { target *-*-* } 9 }

#define X "X"
#define X "Y"         // { dg-bogus "-Wbuiltin-macro-redefined" }
                      // { dg-warning "-:\"X\" redefined" "not-builtin-2" { target *-*-* } .-1 }
                      // { dg-message "-:previous definition" "previous-2" { target *-*-* } 15 }
