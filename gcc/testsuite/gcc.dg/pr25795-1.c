/* { dg-do compile } */
/* { dg-options "-O3 -fwhole-program" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
/* { dg-final { scan-assembler-not "mystr" } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */


extern const char *mystr;       /* normally in a header */
const char *mystr;
int
main()
{
}
