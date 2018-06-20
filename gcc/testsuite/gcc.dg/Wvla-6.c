/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c89 -Wvla" } */

extern void 
func (int i, int [i]); /* { dg-warning "ISO C90 forbids variable length array" } */
