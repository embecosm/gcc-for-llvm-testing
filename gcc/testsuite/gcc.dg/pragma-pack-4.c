/* PR c/28286 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */


#pragma pack(0.5)         /* { dg-warning "invalid constant" } */
#pragma pack(push,0.5)    /* { dg-warning "invalid constant" } */
#pragma pack(push,x,0.5)  /* { dg-warning "invalid constant" } */
