// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -trigraphs -Wtrigraphs" }

??=  // { dg-warning "trigraph \\?\\?= converted to # .-Wtrigraphs." }
