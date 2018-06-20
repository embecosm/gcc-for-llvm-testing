// { dg-do preprocess }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Werror=comments" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
/* /* */  // { dg-error "\"\.\*\" within comment .-Werror=comment." }

// \
          // { dg-error "multi-line comment .-Werror=comment." "multi-line" { target *-*-* } .-1 }
