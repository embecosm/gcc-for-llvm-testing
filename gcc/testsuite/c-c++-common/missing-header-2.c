/* { dg-options "-fdiagnostics-show-caret" } */
/* { dg-require-effective-target gcc_frontend } */
#include <this-file-does-not-exist.h> /* { dg-error "10: this-file-does-not-exist.h: No such file or directory" } */

/* { dg-begin-multiline-output "" }
 #include <this-file-does-not-exist.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
   { dg-end-multiline-output "" } */
