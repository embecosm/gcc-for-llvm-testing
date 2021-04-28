/* PR debug/97989 */
/* { dg-do preprocess } */
/* { dg-options "-g2 -g3 -P" } */
/* { dg-require-effective-target-flag { -fuse-linker-plugin } } */

#define foo bar
int i;

/* { dg-final { scan-file pr97989-2.i "(^|\\n)#define foo bar($|\\n)" } } */
