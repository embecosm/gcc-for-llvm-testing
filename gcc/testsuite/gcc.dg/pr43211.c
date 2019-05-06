/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct T;

struct S {
  void (*bar)(struct S);
};

void bar(struct T t) {} /* { dg-error "" }  */

void foo(struct S *s)
{
  s->bar = bar;
}

