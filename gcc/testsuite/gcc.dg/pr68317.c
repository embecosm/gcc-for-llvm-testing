/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-unused-value" } */

void bar (int);

void
foo ()
{
 int index = 0;

 for (index; index <= 10; index--)
   /* Result of the following multiply will overflow
      when converted to signed int.  */
   bar ((0xcafe + index) * 0xdead);
}
