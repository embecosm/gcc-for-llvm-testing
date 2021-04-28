/* PR rtl-optimization/92591 */
/* { dg-do compile } */
/* { dg-options "-Os -fmodulo-sched -fmodulo-sched-allow-regmoves --param sms-dfa-history=8" } */
/* { dg-require-effective-target-flag { -fmodulo-sched -fmodulo-sched-allow-regmoves } } */

#include "../gcc.c-torture/execute/pr61682.c"
