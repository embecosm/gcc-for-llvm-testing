/* Test that use of strncpy does not result in a "value computed is
   not used" warning.  */
/* { dg-do compile } */
/* { dg-options "-O2 -Wall -Wno-stringop-truncation" } */
/* { dg-additional-options "-Wno-unknown-warning-option" } */

#include <string.h>
void
f (char *s)
{
  strncpy (s, "::", 2);
}
