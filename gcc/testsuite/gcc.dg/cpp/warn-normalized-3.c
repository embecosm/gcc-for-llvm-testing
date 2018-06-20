// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Werror=normalized=nfc" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
\u0F43  // { dg-error "`.U00000f43' is not in NFC .-Werror=normalized=." }
