/* Test diagnostics for sizeof on void and function types.  Test with
   no special options.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-additional-options "-Wno-unused-value" } */

extern const void v;
void f(void);

void
g (void)
{
  sizeof (v);
  sizeof (void);
  sizeof (f);
  sizeof (void (void));
}
