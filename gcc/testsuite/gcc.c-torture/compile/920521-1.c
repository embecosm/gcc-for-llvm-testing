/* { dg-do compile } */
/* { dg-require-effective-target invalid_inline_asm } */

f(){asm("f":::"cc");}g(x,y){asm("g"::"%r"(x), "r"(y));}
