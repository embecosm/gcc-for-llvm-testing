/* PR c/61854 */
/* { dg-do run } */
/* { dg-options "-std=c89" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

int
main (void)
{
  int i = 0
#if 0
// /*
#else
// */
+1
#endif
;
  if (i != 0)
    __builtin_abort ();
  return 0;
}
