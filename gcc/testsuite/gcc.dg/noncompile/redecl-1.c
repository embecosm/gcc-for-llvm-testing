/* Copyright 2000  Free Software Foundation */
/* by Alexandre Oliva  <aoliva@redhat.com> */
/* { dg-require-effective-target gcc_frontend } */

int
foo ()
{
  int bar; /* { dg-message "note: previous.*decl" "previous.*decl" } */
  volatile int bar; /* { dg-error "conflicting type qualifiers" "conflicting type qualifiers" } */
}
