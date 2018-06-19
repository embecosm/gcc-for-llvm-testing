/* PR target/69100 */
/* Reported by Zdenek Sojka <zsojka@seznam.cz> */

/* { dg-do compile } */
/* { dg-options "-mno-fpu" } */
/* { dg-require-effective-target builtin_apply } */

void
foo (void)
{
  __builtin_apply (0, 0, 0);
}
