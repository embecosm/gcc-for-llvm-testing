/* { dg-do compile } */
/* { dg-options "-O2 -ftree-tail-merge" } */
/* { dg-require-effective-target gcc_internals } */

extern int v1;
extern int v2;
void g (void);

void
f ()
{
  if (v2 || v1)
    (!(v1)) ? (void) 0 : (void) g ();
}
