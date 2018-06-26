/* PR middle-end/45567 */
/* { dg-do compile } */
/* { dg-options "-ftree-ter" } */
/* { dg-require-effective-target gcc_internals } */

unsigned
foo (char c)
{
  return __builtin_popcountl ((unsigned long) c);
}
