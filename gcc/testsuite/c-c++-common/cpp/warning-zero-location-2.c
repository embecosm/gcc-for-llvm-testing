/*
   { dg-options "-D _GNU_SOURCE -fdiagnostics-show-caret" }
   { dg-do compile }
   { dg-require-effective-target gcc_frontend }
 */

#line 4636 "configure"
#include <xxxxxxxxxxxx.h>
int main() { return 0; }

/* { dg-message "" "#include" {target *-*-* } 0 }
