/* { dg-do compile } */
/* { dg-require-profiling "-fprofile-generate" } */
/* { dg-options "-O -fprofile-generate=. -fdump-ipa-cgraph" } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-final { scan-ipa-dump " ./profile-dir-1.gcda" "cgraph" } } */

int
main(void)
{
  return 0;
}

