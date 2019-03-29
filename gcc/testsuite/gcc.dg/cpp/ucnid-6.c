/* { dg-do compile } */
/* { dg-options "-std=c89" } */
/* { dg-additional-options "-Wno-unicode" } */
#define a b(
#define b(x) q
int a\u00aa);
