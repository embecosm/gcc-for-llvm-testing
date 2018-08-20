/* { dg-do compile } */
/* { dg-prune-output "conflicting types for built-in" } */
/* { dg-require-effective-target gcc_internals } */

void *memmove ();

void *
bar ()
{
  return memmove ();
}

/* { dg-prune-output "\\\[-Wbuiltin-declaration-mismatch]" } */
