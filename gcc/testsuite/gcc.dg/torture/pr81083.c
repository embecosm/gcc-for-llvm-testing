/* { dg-do compile } */
/* { dg-additional-options "-Wno-builtin-requires-header" } */

void setjmp();
void func();
void a(int arg)
{
  extern struct { int x; } obj;
  setjmp();
  obj.x = arg;
  arg = arg;
  if (obj.x)
    func();
  if (obj.x)
    func();
}
