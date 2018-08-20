/* PR driver/78863.  */

/* { dg-do compile } */
/* { dg-options "-fsanitize" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "unrecognized command-line option '-fsanitize'; did you mean '-fsanitize='?"  "" { target *-*-* } 0 } */
