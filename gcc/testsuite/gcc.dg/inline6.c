/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu89" } */
static int i;
extern int j;
extern inline int func1 (void) {
  return i++;  /* { dg-warning "static" } */
}
extern inline int func2 (void) {
  return j++;
}
inline int func3 (void) 
{
  return i++;
}
