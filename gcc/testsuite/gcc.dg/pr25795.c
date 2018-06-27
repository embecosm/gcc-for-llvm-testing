/* { dg-do compile } */
/* { dg-options "-O3 -fwhole-program" } */
/* { dg-final { scan-assembler "mystr" } } */
/* { dg-require-effective-target externally_visible } */

extern const char *mystr;       /* normally in a header */
const char *mystr __attribute__ ((externally_visible));
int
main()
{
}
