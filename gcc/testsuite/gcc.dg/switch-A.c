/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  switch (,) { } /* { dg-error "expected expression before" } */
}

