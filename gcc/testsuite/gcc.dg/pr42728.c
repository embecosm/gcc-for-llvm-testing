/* PR debug/42728 */
/* { dg-do compile } */
/* { dg-options "-O1 -fcompare-debug" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (char *a)
{
  char *b;
  for (; *a; a++)
    a = b++;
}
