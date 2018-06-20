/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */


void foo()
{
  sizeof(,); /* { dg-error "expected expression before" } */
}

