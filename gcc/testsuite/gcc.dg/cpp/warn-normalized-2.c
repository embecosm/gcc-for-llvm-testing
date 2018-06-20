// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wnormalized=nfkc" }

\u00AA  // { dg-warning "`.U000000aa' is not in NFKC .-Wnormalized=." }
