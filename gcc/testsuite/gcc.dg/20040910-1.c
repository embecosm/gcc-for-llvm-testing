/* Tests error recovery for invalid code.  */
/* { dg-require-effective-target gcc_frontend } */
__attribute__((foo)  int f (){} /* { dg-error "(parse error|syntax error|expected '\\)') before 'int'" } */
