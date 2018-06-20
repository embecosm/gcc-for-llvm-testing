/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
void foo() 
const char* p = __FUNCTION__; /* { dg-error "" } */
