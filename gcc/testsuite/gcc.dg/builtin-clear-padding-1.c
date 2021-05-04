/* PR libstdc++/88101 */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */
/* { dg-require-effective-target vla_in_struct } */

void
foo (int n)
{
  struct S { char a; int b[n]; long long c; } s;
  __builtin_clear_padding (&s);		/* { dg-message "unimplemented: __builtin_clear_padding not supported for variable length aggregates" } */
}
