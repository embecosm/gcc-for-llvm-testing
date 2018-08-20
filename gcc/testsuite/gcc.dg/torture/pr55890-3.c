/* { dg-do compile } */
/* { dg-require-effective-target gcc_internals } */

void *memmove ();

void *
bar ()
{
  return memmove ();
}
