/* { dg-do compile } */
/* { dg-options "--param max-early-inliner-iteration=3" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-error "invalid --param name .max-early-inliner-iteration.; did you mean .max-early-inliner-iterations.?"  "" { target *-*-* } 0 } */

