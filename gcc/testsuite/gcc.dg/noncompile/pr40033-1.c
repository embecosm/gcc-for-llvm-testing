/* ICE from error_mark_node being wrapped in a C_MAYBE_CONST_EXPR.  PR
   40033.  */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  ({ 0,; }); /* { dg-error "expected" } */
}
