// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Werror=unused-macros" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
#define X X  // { dg-error "-:macro \"X\" is not used .-Werror=unused-macros." }
