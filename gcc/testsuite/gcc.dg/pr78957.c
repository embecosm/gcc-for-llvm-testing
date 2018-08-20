/* PR driver/78957 */
/* { dg-do compile } */
/* { dg-options "-fno-sso-struct=none" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "unrecognized command-line option" "" { target *-*-* } 0 } */

int i;
