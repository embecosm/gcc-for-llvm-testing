/* { dg-do compile } */
/* { dg-options "-finstrument-functions" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

void fn () { }

/* { dg-final { scan-assembler "__cyg_profile_func_enter" } } */
/* { dg-final { scan-assembler "__cyg_profile_func_exit" } } */
