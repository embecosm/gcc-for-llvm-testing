/* PR c/61854 */
/* { dg-do run } */
/* { dg-options "-std=c89" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#define h(x) #x
#define s(x) h(x)
#define foo //

int
main (void)
{
  if (__builtin_memcmp (s(foo), "//", 3) != 0)
    __builtin_abort ();
  return 0;
}
