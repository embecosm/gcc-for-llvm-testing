/* { dg-do compile } */
/* { dg-additional-options "-Wno-unused-value" } */
/* { dg-additional-options "-Wno-pointer-bool-conversion" } */
/* { dg-additional-options "-Wno-parentheses" } */

unsigned a;
short b;
char c, d, e;
void fn1();
void fn2() {
    a++;
    for (; a;)
      fn1(0, 0);
}
void fn3() {
    fn2();
l1:;
   unsigned char f;
   short g;
   unsigned char *h = &f;
   g += &h ? e ? g = 1 : 0 : 0;
   d = g;
   c *f;
   if (d & (b %= *h) < f * d / (d -= 0))
     goto l1;
}
