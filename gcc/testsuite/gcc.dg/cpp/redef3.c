/* Test for redefining macros with mismatch token count (and the oddity). */

/* { dg-do preprocess } */
/* { dg-options "-DC -DD=1 -DE" } */
/* { dg-require-effective-target gcc_frontend } */

#define A
#define A 1
#define B 2 3
#define B 2
#define C 1
#define D 1 2
#define E

/* { dg-warning "-:redefined" "redef A"      { target *-*-* } 8  }
   { dg-warning "-:redefined" "redef B"      { target *-*-* } 10 }
   { dg-warning "-:redefined" "redef D"      { target *-*-* } 12 }
   { dg-warning "-:redefined" "redef E"      { target *-*-* } 13 }
   { dg-message "-:previous"  "prev def A"   { target *-*-* } 7  }
   { dg-message "-:previous"  "prev def B"   { target *-*-* } 9  }
   { dg-message "-:previous"  "prev def D/E" { target *-*-* } 0  }
*/
