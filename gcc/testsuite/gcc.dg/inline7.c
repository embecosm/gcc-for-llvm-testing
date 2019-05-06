/* { dg-do compile } */
/* { dg-options "-std=gnu89" } */
/* { dg-require-effective-target gcc_frontend } */
extern inline void func1 (void) {
  static int i;  /* { dg-warning "static" } */
}
inline void func3 (void) 
{
  static int i;
}
