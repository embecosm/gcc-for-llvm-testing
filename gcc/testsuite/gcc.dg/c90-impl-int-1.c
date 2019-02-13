/* Test for implicit int: in C90 only.  */
/* Origin: Joseph Myers <jsm28@cam.ac.uk> */
/* { dg-do compile } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */
/* { dg-additional-options "-Wno-return-type" } */

extern foo;

bar (void) { }
