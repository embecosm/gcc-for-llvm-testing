/* { dg-do compile } */
/* { dg-options "-finstrument-functions -finstrument-functions-exclude-file-list=instrument-3" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

void fn () { }

/* { dg-final { scan-assembler-not "__cyg_profile_func_enter" } } */
/* { dg-final { scan-assembler-not "__cyg_profile_func_exit" } } */
