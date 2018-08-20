/* Test -fno-gnu89-extern-inline.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu89 -fno-gnu89-inline" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "only supported in GNU99 or C99 mode" "" { target *-*-* } 0 } */
