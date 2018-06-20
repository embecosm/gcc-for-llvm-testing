// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wtrigraphs" }

??=  // { dg-warning "trigraph \\?\\?= ignored, use -trigraphs to enable .-Wtrigraphs." }
