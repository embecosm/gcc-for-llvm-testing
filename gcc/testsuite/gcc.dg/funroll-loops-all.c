/* PR 17594 */
/* { dg-do compile } */
/* { dg-options "-funroll-loops-all" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "unrecognized command-line option '-funroll-loops-all'" "" { target *-*-* } 0 } */
