/* { dg-options "-fdiagnostics-show-caret" } */
/* { dg-require-effective-target gcc_frontend } */

void bar(void);
void foo(void)
{
  bar() /* { dg-error "expected ';' before '.' token" } */
}
/* { dg-begin-multiline-output "" }
   bar()
        ^
        ;
 }
 ~       
   { dg-end-multiline-output "" } */
