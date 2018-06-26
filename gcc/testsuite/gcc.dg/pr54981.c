/* { dg-do compile } */
/* { dg-options "-O -ftree-loop-distribute-patterns -fcompare-debug" } */
/* { dg-require-effective-target gcc_internals } */

extern void bar(unsigned *, char *);

void foo(char *s)
{
  unsigned i;
  char t[2];

  bar(&i, t);

  for (i = 0; i < 2; i++)
    s[i] = t[i];
}
