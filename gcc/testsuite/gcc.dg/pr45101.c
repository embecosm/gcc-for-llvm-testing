/* PR rtl-optimization/45101 */
/* { dg-do compile } */
/* { dg-options "-O2 -fgcse -fgcse-las" } */
/* { dg-require-effective-target gcc_internals } */

struct
{
  int i;
} *s;

extern void bar (void);

void foo ()
{
  !s ? s->i++ : bar ();
}
